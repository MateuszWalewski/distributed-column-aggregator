#include "TCPServer.h"
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <vector>

using boost::asio::ip::tcp;

template void TCPServer::Read<double>( std::vector<double>& data, const std::vector<int>& dataSize );
template void TCPServer::Read<float>( std::vector<float>& data, const std::vector<int>& dataSize );
template void TCPServer::Read<int>( std::vector<int>& data, const std::vector<int>& dataSize );

TCPServer::TCPServer( boost::asio::io_context& io_context )
{
    try
    {
        auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
        auto port = pCInstance.GetTcpPorts();
        for ( auto& p : port )
        {
            _acceptor.emplace_back( io_context, tcp::endpoint( tcp::v4(), p ) );
        }
    }
    catch ( const std::exception& e )
    {
        std::cerr << "Exception in TCPServer::TCPServer: " << e.what() << std::endl;
    }

    std::cout << "Server info has been intialized" << std::endl;
}

void TCPServer::Accept()
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    int nOfNodes = pCInstance.GetNumberOfNodes();
    auto port = pCInstance.GetTcpPorts();
    try
    {
        for ( int i = 0; i < nOfNodes; i++ )
        {
            _session.emplace_back( std::make_unique<tcp::socket>( _acceptor[i].accept() ) );
            std::cout << "Connection from peer on the port: " << port[i] << " accepted" << '\n';
            std::cout << "Session " << i + 1 << " has been established" << std::endl;
        }
    }
    catch ( const std::exception& e )
    {
        std::cerr << "Exception in TCPServer::Accept(): " << e.what() << std::endl;
    }
}

template <typename T>
void TCPServer::Read( std::vector<T>& data, const std::vector<int>& dataSize )
{
    try
    {
        auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
        int nOfNodes = pCInstance.GetNumberOfNodes();
        int offset = 0;
        for ( int i = 0; i < nOfNodes; i++ )
        {
            _session[i].FetchDataFromPeer( data, dataSize[i], offset );
            offset += dataSize[i];
        }
    }
    catch ( const std::exception& e )
    {
        std::cerr << "Exception in TCPServer::Read(): " << e.what() << std::endl;
    }
}

TCPServer::Session::Session( std::unique_ptr<tcp::socket>&& socket )
{
    _socket = std::move( socket );
}

template <typename T>
void TCPServer::Session::FetchDataFromPeer( std::vector<T>& data, int dataSize, int offset )
{
    try
    {
        boost::system::error_code error;
        std::vector<T> temp;
        temp.resize( dataSize );

        boost::asio::read( *_socket, boost::asio::buffer( temp ), error );
        if ( error == boost::asio::error::eof )
            return;
        else if ( error )
            throw boost::system::system_error( error );

        std::copy( temp.begin(), temp.end(), data.begin() + offset );
    }
    catch ( const std::exception& e )
    {
        std::cerr << "Exception in TCPServer::Session::FetchDataFromPeer(): " << e.what() << std::endl;
    }
}
