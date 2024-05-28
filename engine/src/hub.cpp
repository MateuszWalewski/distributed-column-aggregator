#include "constants.h"
#include "python_bindings.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <Tools/Utility.h>
#include <rpc/client.h>

void InitialiseHub() {
    auto rpcConnectionInfo = util::SplitStringToVector(std::getenv("RPC_CONNECTIONS"));
    auto tcpConnectionInfo = util::SplitStringToVector(std::getenv("TCP_PORTS"));
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    cMInstance.LoadConnectionInfo(tcpConnectionInfo);
    cMInstance.setConfigParameter(NUMBER_OF_NODES, rpcConnectionInfo.size());

    RpcClientHandlers rpcClientHandlers;
    for (const auto& info : rpcConnectionInfo) {
        std::istringstream iss(info);
        std::string ipAddress, port;

        std::getline(iss, ipAddress, ':');
        std::getline(iss, port);

        uint portNumber;
        try {
            portNumber = boost::lexical_cast<uint>(port);
        } catch (const boost::bad_lexical_cast& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        rpcClientHandlers.push_back(std::make_unique<rpc::client>(ipAddress, portNumber));
    }

    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    rpcInstance.SetRpcClientInfo(move(rpcClientHandlers));
}
