
#include "Session.h"
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
    TCPServer();

    void DoAccept();
    // make this class template and this vector according to data type to be send

    template <typename T>
    void Read( std::vector<T>& data, std::vector<int>& dataSize );

private:
    std::vector<std::shared_ptr<tcp::acceptor>> acceptor_;
    std::vector<std::shared_ptr<Session>> session;
    std::vector<std::shared_ptr<boost::asio::io_context>> context;
};