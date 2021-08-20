#pragma once
#include <memory>
#include <string>

#include "Networking/SessionHandlerHub.h"
#include "ParameterController/ParameterController.h"

#define CTX() GlobalContextHub::Instance()

class GlobalContextHub
{
private:
    GlobalContextHub();
    std::shared_ptr<SessionHandlerHub> mSessionHandler;

public:
    static GlobalContextHub & Instance();

    SessionHandlerHub & GetSessionHandler();
};