#include "TCPClient.h"
#include "constants.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace boost::asio;
using ip::tcp;

template void TCPClient::Send<double>(std::vector<double>& data);
template void TCPClient::Send<float>(std::vector<float>& data);
template void TCPClient::Send<int>(std::vector<int>& data);

TCPClient::TCPClient(boost::asio::io_context& io_context) : _resolver(io_context) {
    _socket = std::make_unique<tcp::socket>(io_context);
}

void TCPClient::Connect() {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    std::string hubIp = std::get<std::string>(cMInstance.getConfigParameter(TCP_SERVER_IP));
    std::string hubPort = std::get<std::string>(cMInstance.getConfigParameter(TCP_SERVER_PORT));
    boost::asio::ip::tcp::resolver::query query(hubIp, hubPort);
    boost::asio::ip::tcp::resolver::iterator iter = _resolver.resolve(query);

    _socket->connect(iter->endpoint());
    std::cout << "TCP connection to: " << hubIp << ":" << hubPort << " has been established." << std::endl;
}

template <typename T>
void TCPClient::Send(std::vector<T>& data) {
    try {
        Connect();
        boost::system::error_code error;
        boost::asio::write(*_socket, boost::asio::buffer(data), error);
        if (!error) {
            std::cout << "Client sent data sucessfully!" << std::endl;
        } else {
            throw boost::system::system_error(error);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in TCPClient::Send: " << e.what() << std::endl;
    }
}
