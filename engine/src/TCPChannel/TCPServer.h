
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>

#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::tcp;

class TCPServer {
public:
    TCPServer(boost::asio::io_context& io_context);

    void Accept();

    template <typename T>
    void Read(std::vector<T>& data, const std::vector<int>& dataSize);

    class Session {
    public:
        Session(std::unique_ptr<tcp::socket>&& socket);

        template <typename T>
        void FetchDataFromPeer(std::vector<T>& data, int dataSize, int offset);

    private:
        std::unique_ptr<tcp::socket> _socket;
    };

private:
    std::vector<tcp::acceptor> _acceptor;
    std::vector<Session> _session;
};
