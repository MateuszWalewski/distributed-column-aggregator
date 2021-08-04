#pragma once
#include "../Networking/SessionHandler.h"
#include <string>
#include <memory>

#define CTX() GlobalContext::Instance()

class GlobalContext
{

    private:
    GlobalContext();
    std::unique_ptr<SessionHandler> mSessionHanlderServer;
    std::unique_ptr<SessionHandler> mSessionHanlderClient;


    std::string mHubIP;
    uint mHubPort;
    uint mNodePort;
    std::string mNodeIP;


    public:
    static GlobalContext & Instance();

    SessionHandler & GetSessionHandlerServer();
    SessionHandler & GetSessionHandlerClient();


};