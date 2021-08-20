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

public:
    static GlobalContext & Instance();

    SessionHandler & GetSessionHandler();
};