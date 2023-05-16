#include "Session.h"

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

Session::Session( tcp::socket socket ) : socket_( std::move( socket ) )
{
    container1.resize( max_len );
};

void Session::Read( std::vector<char>& data )
{
    // auto self( shared_from_this() );
    // async_read( socket_, boost::asio::buffer( container1, max_len ),
    //             [this, self, &data]( boost::system::error_code ec, std::size_t length ) {
    //                 if ( !ec )
    //                 {
    //                     container1.resize( length );
    //                     data.insert( data.end(), container1.begin(), container1.end() );
    //                 }
    //             } );
}
