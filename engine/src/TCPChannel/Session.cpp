#include "Session.h"

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

template void Session::Read<double>( std::vector<double>& data, int offset, int dataSize );
template void Session::Read<float>( std::vector<float>& data, int offset, int dataSize );
template void Session::Read<int>( std::vector<int>& data, int offset, int dataSize );

Session::Session( tcp::socket socket ) : socket_( std::move( socket ) ){};
// make it template
template <typename T>
void Session::Read( std::vector<T>& data, int offset, int dataSize )
{
    std::cout << "offset = " << offset << ", dataSize = " << dataSize << std::endl;
    // make it template
    std::vector<int> temp;
    temp.resize( dataSize );
    boost::system::error_code ec;
    size_t length = socket_.read_some( boost::asio::buffer( temp ), ec );
    temp.resize( length );
    std::cout << "temp.size = " << temp.size() << std::endl;
    // data.insert(data.end(), temp.begin(), temp.end());
    std::copy( temp.begin(), temp.end(), data.begin() + offset );

    // auto self( shared_from_this() );
    // async_read( socket_, boost::asio::buffer( temp, max_len ),
    //             [this, self, &data]( boost::system::error_code ec, std::size_t length ) {
    //                 if ( !ec )
    //                 {
    //                     temp.resize( length );
    //                     data.insert( data.end(), temp.begin(), temp.end() );
    //                 }
    //             } );
}
