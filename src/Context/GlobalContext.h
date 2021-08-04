#pragma once
#include "../Networking/SessionHandler.h"
#include <string>
#include <memory>

// #define CTX() GlobalContext::Instance()

class GlobalContext
{

    private:
    GlobalContext(bool hub);
    std::shared_ptr<SessionHandler> mSessionHandler;


    std::string mHubIP;
    uint mHubPort;
    uint mNodePort;
    std::string mNodeIP;
    // Kick if off!!
    bool mIsHub = false;


    public:
    static GlobalContext & Instance(bool hub);

    SessionHandler & GetSessionHandler();

    void Hello();


};