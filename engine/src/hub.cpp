#include "python_bindings.h"
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterController/ParameterControllerHub.h>
#include <Tools/Utility.h>
#include <rpc/client.h>

void InitialiseHub() {
    auto rpcConnectionInfo = util::SplitStringToVector(std::getenv("RPC_CONNECTIONS"));
    auto tcpConnectionInfo = util::SplitStringToVector(std::getenv("TCP_CONNECTIONS"));
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    pCInstance.LoadHubConnectionInfo(rpcConnectionInfo, tcpConnectionInfo);
    pCInstance.PrintHubConnectionInfo();

    RpcClientHandlers rpcClientHandlers;
    auto serverInfo = pCInstance.GetServerInfo();

    for (const auto& info : serverInfo) {
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
