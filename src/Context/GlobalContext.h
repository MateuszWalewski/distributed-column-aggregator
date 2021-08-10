#pragma once
#include <memory>
#include <string>

#include "Networking/SessionHandler.h"
#include "ParameterController/ParameterController.h"

#define CTX() GlobalContext::Instance()

class GlobalContext
{
private:
    GlobalContext();
    std::shared_ptr<SessionHandler> mSessionHandler;

    std::string mHubIP;
    uint mHubPort;
    uint mNodePort;
    std::string mNodeIP;

public:
    static GlobalContext & Instance();

    SessionHandler & GetSessionHandler();

    void Hello();
};