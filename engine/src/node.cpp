#include "bindings.h"
#include "constants.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

int InitialiseNode() {
    uint rpcServerPort;
    try {
        rpcServerPort = boost::lexical_cast<uint>(std::getenv("RPC_PORT"));
    } catch (const boost::bad_lexical_cast& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    std::vector<std::string> addressParts;
    boost::split(addressParts, std::getenv("TCP_CONNECTION"), boost::is_any_of(":"));
    if (addressParts.size() != 2) {
        std::cerr << "Wrong TCP/IP server connection details " << std::endl;
        return 1;
    }
    cMInstance.setConfigParameter(TCP_SERVER_IP, addressParts[0]);
    cMInstance.setConfigParameter(TCP_SERVER_PORT, addressParts[1]);
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    rpcInstance.SetRpcServerInfo(std::make_unique<rpc::server>(rpcServerPort));
    performBindings();
    std::cout << "Listening on port: " << std::getenv("RPC_PORT") << std::endl;
    rpcInstance.RunServer();
    return 0;
}

int main() {
    return InitialiseNode();
}
