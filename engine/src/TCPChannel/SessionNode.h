#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

class SessionNode
{
public:
    SessionNode();
    void Connect();
    void Send();

private:
    std::shared_ptr<tcp::socket> socket_;
};
