#include <Session.h>
#include <TCPServer.h>

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

void TCPServer::do_accept()
{
    // change into loop over nodes
    acceptor_.async_accept( [this]( boost::system::error_code ec, tcp::socket socket ) {
        if ( !ec )
        {
            // set session for each node and save to container (similarly to RPC hadlers)
            session = std::make_shared<Session>( std::move( socket ) );
        }

        do_accept();
    } );
}
