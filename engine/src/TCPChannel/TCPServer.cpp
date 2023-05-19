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

TCPServer::TCPServer()
{
    std::cout << "HEllo" << std::endl;
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    // acceptor_.resize( pCInstance.GetNumberOfNodes() );
    // boost::asio::io_context io_context;
    // std::cout << "HEllo" << std::endl;
    // for ( size_t i = 0; i < pCInstance.GetNumberOfNodes(); i++ )
    // {
    //     auto port = pCInstance.GetNodesTCPPorts()[i];
    //     std::cout << "TCP port set on node nr: " << std::to_string(i + 1) << std::to_string(port) << std::endl;
    //     acceptor_[i] = std::make_shared<tcp::acceptor>( io_context, tcp::endpoint( tcp::v4(), port ) );
    // }
    size_t nOfNodes = pCInstance.GetNumberOfNodes();

    acceptor_.resize( nOfNodes );
    context.resize( nOfNodes );
    // offset.push_back(3);
    // offset.push_back(4);
    // data.resize(offset[0] + offset[1]);
    for ( int i = 0; i < nOfNodes; i++ )
    {
        auto port = pCInstance.GetNodesTCPPorts()[i];
        context[i] = std::make_shared<boost::asio::io_context>();
        acceptor_[i] = std::make_shared<tcp::acceptor>( *context[i], tcp::endpoint( tcp::v4(), port ) );
        std::cout << "Accepting on port:" << port << std::endl;
    }
}

void TCPServer::DoAccept()
{
    // change into loop over nodes
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    session.resize( pCInstance.GetNumberOfNodes() );

    for ( auto& a : acceptor_ )
    {
        session.push_back( std::make_shared<Session>( a->accept() ) );
    }
}

template <typename T>
void TCPServer::Read( std::vector<T>& data, std::vector<int>& dataSize )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    size_t nOfNodes = pCInstance.GetNumberOfNodes();
    int offset = 0;
    for ( int i = 0; i < nOfNodes; i++ )
    {
        session[i]->Read( data, offset, dataSize[i] );
        offset += dataSize[i];
    }
}
