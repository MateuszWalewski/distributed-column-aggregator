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

private:
    void Read( std::vector<char>& data );

    tcp::socket socket_;
    int max_len = 19;
    std::vector<char> container1;
};