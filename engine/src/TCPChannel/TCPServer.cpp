#include "TCPServer.h"

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

TCPServer::TCPServer()
{
    std::cout << "HEllo" << std::endl;
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    acceptor_.resize( pCInstance.GetNumberOfNodes() );
    boost::asio::io_context io_context;
    std::cout << "HEllo" << std::endl;
    for ( size_t i = 0; i < pCInstance.GetNumberOfNodes(); i++ )
    {
        auto port = pCInstance.GetNodesTCPPorts()[i];
        std::cout << "TCP port set on node nr: " << std::to_string(i + 1) << std::to_string(port) << std::endl;
        acceptor_[i] = std::make_shared<tcp::acceptor>( io_context, tcp::endpoint( tcp::v4(), port ) );
    }
}

void TCPServer::DoAccept()
{
    // change into loop over nodes
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    session.resize( pCInstance.GetNumberOfNodes() );
    for ( int i = 0; i < pCInstance.GetNumberOfNodes(); i++ )
    {
        std::cout << "Started accepting for node nr: " << std::to_string(i + 1) << std::endl;
        acceptor_[i]->async_accept( [this, &i]( boost::system::error_code ec, tcp::socket socket ) {
            if ( !ec )
            {
                // set session for each node and save to container (similarly to RPC hadlers)
                session[i] = std::make_shared<Session>( std::move( socket ) );
            }
        } );
    }
}

void TCPServer::Read( std::vector<char>& data )
{
    for ( auto& s : session )
    {
        s->Read( data );
    }
}
