
#include <Loki/Singleton.h>
#include <ParameterController/ParameterControllerHub.h>
#include "Session.h"

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
    void Read( std::vector<char>& data );

private:
    std::vector<std::shared_ptr<tcp::acceptor>> acceptor_;
    std::vector<std::shared_ptr<Session>> session;
};