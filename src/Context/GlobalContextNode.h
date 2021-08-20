#pragma once
#include <memory>
#include <string>

#include "Networking/SessionHandlerNode.h"
#include "ParameterController/ParameterController.h"

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