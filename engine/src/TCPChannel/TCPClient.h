#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

class TCPClient {
public:
    TCPClient(boost::asio::io_context& io_context);

    template <typename T>
    void Send(std::vector<T>& data);

private:
    void Connect();
    std::unique_ptr<tcp::socket> _socket;
    boost::asio::ip::tcp::resolver _resolver;
};
