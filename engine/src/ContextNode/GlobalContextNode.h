#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "NetworkingNode/SessionHandlerNode.h"

#define CTX() GlobalContextNode::Instance()

class GlobalContextNode
{
private:
    GlobalContextNode();
    std::shared_ptr<SessionHandlerNode> mSessionHandler;

public:
    static GlobalContextNode & Instance();

    SessionHandlerNode & GetSessionHandler();
};