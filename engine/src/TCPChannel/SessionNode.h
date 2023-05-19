#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

class SessionNode
{
public:
    SessionNode();

    template <typename T>
    void Send( std::vector<T>& data );

private:
    void Connect();
    std::shared_ptr<tcp::socket> socket_;
};
