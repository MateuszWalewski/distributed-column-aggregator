#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session( tcp::socket socket );

    template <typename T>
    void Read( std::vector<T>& data, int offset, int dataSize );

private:
    tcp::socket socket_;
};