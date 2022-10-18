#pragma once
#include <memory>
#include <string>

#include "Networking/RPCManager.h"
#include "ParameterController/ParameterControllerHub.h"

#define CTX() GlobalContextHub::Instance()

class GlobalContextHub
{
private:
    GlobalContextHub();
    std::shared_ptr<RPCManager> mRpcManager;

public:
    static GlobalContextHub & Instance();

    RPCManager & GetRPCManager();
};