
#include <Loki/Singleton.h>
#include <ParameterController/ParameterControllerHub.h>

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
    TCPServer( boost::asio::io_context& io_context );

    void Accept();

    template <typename T>
    void Read( std::vector<T>& data, std::vector<int>& dataSize );

    class Session
    {
    public:
        Session( std::unique_ptr<tcp::socket>&& socket );

        template <typename T>
        void FetchDataFromPeer( std::vector<T>& data, int dataSize, int offset );

    private:
        std::unique_ptr<tcp::socket> socket_;
    };

private:
    std::vector<tcp::acceptor> acceptor_;
    std::vector<Session> session;
};
