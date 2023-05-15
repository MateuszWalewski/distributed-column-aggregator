#include <SessionNode.h>

#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using ip::tcp;

SessionNode::SessionNode( boost::asio::io_service io_service )
{
    socket_ = std::make_shared<tcp::socket>( io_service );
}

void SessionNode::Connect()
{
    // take port param from paramController
    socket_->connect( tcp::endpoint( boost::asio::ip::address::from_string( "127.0.0.1" ), 1234 ) );
}

void SessionNode::Send()
{
    boost::system::error_code error;
    const std::string msg = "Heldalo from Client!";
    //  change to data from container
    boost::asio::write( socket_, boost::asio::buffer( msg ), error );
    if ( !error )
    {
        // cout << "Client sent hello message!" << endl;
    }
}
