
#include <Session.h>

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using boost::asio::ip::tcp;

class TCPServer
{
public:
    TCPServer( boost::asio::io_context& io_context, short port ) : acceptor_( io_context, tcp::endpoint( tcp::v4(), port ) )
    {
    }

private:
    void do_accept();
    tcp::acceptor acceptor_;
    //   should be changed to vector with session for each node
    std::shared_ptr<Session> session;
};