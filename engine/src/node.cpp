#include "bindings.h"
#include "constants.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>

int InitialiseNode() {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    if (!cMInstance.LoadConnectionInfoOnNode()) {
        return 1;
    }
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    rpcInstance.SetRpcServerInfo(
        std::make_unique<rpc::server>(std::get<uint16_t>(cMInstance.getConfigParameter(RPC_SERVER_PORT))));
    performBindings();
    rpcInstance.RunServer();
    return 0;
}

int main() {
    return InitialiseNode();
}
