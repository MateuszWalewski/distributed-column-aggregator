#include <Loki/Singleton.h>
#include <ParameterControllerNode/ParameterControllerNode.h>
#include "SessionNode.h"

#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using ip::tcp;

SessionNode::SessionNode()
{
    boost::asio::io_service io_service;
    socket_ = std::make_shared<tcp::socket>( io_service );
}

void SessionNode::Connect()
{
    // take port param from paramController
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();
    std::cout << "Connected on port: " << std::to_string(pCInstance.GetNodeTCPPort()) << std::endl;
    socket_->connect( tcp::endpoint( boost::asio::ip::address::from_string( "127.0.0.1" ), pCInstance.GetNodeTCPPort() ) );
}

void SessionNode::Send()
{
    boost::system::error_code error;
    const std::string msg = "Heldalo from Client!";
    //  change to data from container
    boost::asio::write( *socket_, boost::asio::buffer( msg ), error );
    if ( !error )
    {
        // cout << "Client sent hello message!" << endl;
    }
}
