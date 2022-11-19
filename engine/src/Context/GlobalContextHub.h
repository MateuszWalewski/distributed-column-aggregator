#pragma once
#include <memory>
#include <string>
#include <tuple>

#include "Networking/RPCManager.h"

#include "ParameterController/ParameterControllerHub.h"

#define CTX() GlobalContextHub::Instance()

class GlobalContextHub
{
private:
    GlobalContextHub();
    // TODO: Decouple GlobalContext from concrete RPCManager class. Inverse the dependency!
    std::shared_ptr<RPCManager> mRPCManager;

public:
    static GlobalContextHub& Instance();

    RPCManager& GetRPCManager();
};