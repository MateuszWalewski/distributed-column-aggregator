#include "SessionNode.h"
#include <Loki/Singleton.h>
#include <ParameterControllerNode/ParameterControllerNode.h>

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace boost::asio;
using ip::tcp;

template void SessionNode::Send<double>( std::vector<double>& data );
template void SessionNode::Send<float>( std::vector<float>& data );
template void SessionNode::Send<int>( std::vector<int>& data );

SessionNode::SessionNode()
{
    boost::asio::io_service io_service;
    socket_ = std::make_shared<tcp::socket>( io_service );
}

void SessionNode::Connect()
{
    // take port param from paramController
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();
    std::cout << "Connected on port: " << std::to_string( pCInstance.GetNodeTCPPort() ) << std::endl;
    socket_->connect( tcp::endpoint( boost::asio::ip::address::from_string( "127.0.0.1" ), pCInstance.GetNodeTCPPort() ) );
}

// make it template according to data type to be send
template <typename T>
void SessionNode::Send( std::vector<T>& data )
{
    Connect();
    boost::system::error_code error;
    //  change to data from container
    boost::asio::write( *socket_, boost::asio::buffer( data ), error );
    if ( !error )
    {
        // cout << "Client sent hello message!" << endl;
    }
}
