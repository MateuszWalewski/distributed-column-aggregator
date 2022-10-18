#pragma once
#include "Networking/RPCManager.h"
#include <memory>
#include <string>
#include <unordered_map>

#define CTX() GlobalContextNode::Instance()

class GlobalContextNode
{
private:
    GlobalContextNode();
    std::shared_ptr<RPCManager> mRpcManager;

public:
    static GlobalContextNode & Instance();

    RPCManager & GetRPCManager();
};