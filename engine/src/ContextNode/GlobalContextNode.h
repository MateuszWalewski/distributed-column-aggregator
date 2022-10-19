#pragma once
#include "ColumnStorage/ColumnStorage.h"
#include "Networking/RPCManager.h"
#include <memory>
#include <string>
#include <unordered_map>

#define CTX() GlobalContextNode::Instance()

class GlobalContextNode
{
private:
    GlobalContextNode();
    std::shared_ptr<RPCManager> mRPCManager;
    std::shared_ptr<ColumnStorage> mColumnStorage;

public:
    static GlobalContextNode & Instance();

    RPCManager & GetRPCManager();
    ColumnStorage & GetColumnStorage();
};