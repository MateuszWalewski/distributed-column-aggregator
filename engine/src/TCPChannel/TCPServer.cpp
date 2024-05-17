#include "TCPServer.h"

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

template void TCPServer::Read<double>( std::vector<double>& data, std::vector<int>& dataSize );
template void TCPServer::Read<float>( std::vector<float>& data, std::vector<int>& dataSize );
template void TCPServer::Read<int>( std::vector<int>& data, std::vector<int>& dataSize );

TCPServer::TCPServer( boost::asio::io_context& io_context )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    auto port = pCInstance.GetNodesTCPPorts();
    for ( auto& p : port )
    {
        acceptor_.emplace_back( io_context, tcp::endpoint( tcp::v4(), p ) );
    }

    std::cout << "Server info has been intialized" << std::endl;
    ;
}

void TCPServer::Accept()
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    int nOfNodes = pCInstance.GetNumberOfNodes();
    auto port = pCInstance.GetNodesTCPPorts();
    for ( int i = 0; i < nOfNodes; i++ )
    {
        session.push_back( std::make_shared<Session>( std::make_shared<tcp::socket>( acceptor_[i].accept() ) ) );
        std::cout << "Connection from peer on the port: " << port[i] << " accepted" << '\n';
        std::cout << "Session " << i + 1 << " has been established" << std::endl;
    }
}

template <typename T>
void TCPServer::Read( std::vector<T>& data, std::vector<int>& dataSize )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    int nOfNodes = pCInstance.GetNumberOfNodes();
    int offset = 0;
    for ( int i = 0; i < nOfNodes; i++ )
    {
        session[i]->FetchDataFromPeer( data, dataSize[i], offset );
        offset += dataSize[i];
    }
}

TCPServer::Session::Session( std::shared_ptr<tcp::socket> socket )
{
    socket_ = std::move( socket );
}

template <typename T>
void TCPServer::Session::FetchDataFromPeer( std::vector<T>& data, int dataSize, int offset )
{
    try
    {
        boost::system::error_code error;
        std::vector<T> temp;
        temp.resize( dataSize );

        boost::asio::read( *socket_, boost::asio::buffer( temp ), error );

        if ( error == boost::asio::error::eof )
            return; // Connection closed cleanly by peer.
        else if ( error )
            throw boost::system::system_error( error ); // Some other error.

        std::copy( temp.begin(), temp.end(), data.begin() + offset );
    }
    catch ( std::exception& e )
    {
        std::cerr << "Exception in thread: " << e.what() << std::endl;
    }
}
