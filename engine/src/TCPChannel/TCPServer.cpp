#include "TCPServer.h"
#include "constants.h"
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <vector>

using boost::asio::ip::tcp;

template void TCPServer::Read<double>(std::vector<double>& data, const std::vector<int>& dataSize);
template void TCPServer::Read<float>(std::vector<float>& data, const std::vector<int>& dataSize);
template void TCPServer::Read<int>(std::vector<int>& data, const std::vector<int>& dataSize);

TCPServer::TCPServer(boost::asio::io_context& io_context) {
    try {
        auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
        for (size_t i = 0; i < std::get<size_t>(cMInstance.getConfigParameter(NUMBER_OF_NODES)); i++) {
            _acceptor.emplace_back(
                io_context,
                tcp::endpoint(tcp::v4(), std::get<uint>(cMInstance.getConfigParameter(TCP_SERVER_PORT + std::to_string(i)))));
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in TCPServer::TCPServer: " << e.what() << std::endl;
    }
}

void TCPServer::Accept() {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    try {
        for (size_t i = 0; i < std::get<size_t>(cMInstance.getConfigParameter(NUMBER_OF_NODES)); i++) {
            _session.emplace_back(std::make_unique<tcp::socket>(_acceptor[i].accept()));
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in TCPServer::Accept(): " << e.what() << std::endl;
    }
}

template <typename T>
void TCPServer::Read(std::vector<T>& data, const std::vector<int>& dataSize) {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    int offset = 0;
    std::vector<std::future<void>> futures;
    for (size_t i = 0; i < std::get<size_t>(cMInstance.getConfigParameter(NUMBER_OF_NODES)); ++i) {
        futures.emplace_back(std::async(std::launch::async, &Session::template FetchDataFromPeer<T>, &_session[i], std::ref(data),
                                        dataSize[i], offset));
        offset += dataSize[i];
    }

    for (auto& future : futures) {
        future.wait();
    }
}

TCPServer::Session::Session(std::unique_ptr<tcp::socket>&& socket) {
    _socket = std::move(socket);
}

template <typename T>
void TCPServer::Session::FetchDataFromPeer(std::vector<T>& data, int dataSize, int offset) {
    try {
        boost::system::error_code error;
        std::vector<T> temp;
        temp.resize(dataSize);

        boost::asio::read(*_socket, boost::asio::buffer(temp), error);
        if (error) {
            throw boost::system::system_error(error);
        }

        std::copy(temp.begin(), temp.end(), data.begin() + offset);
    } catch (const std::exception& e) {
        std::cerr << "Exception in TCPServer::Session::FetchDataFromPeer(): " << e.what() << std::endl;
    }
}
