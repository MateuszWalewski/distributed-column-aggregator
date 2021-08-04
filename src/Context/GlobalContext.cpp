#include "GlobalContext.h"


GlobalContext::GlobalContext() : mHubIP("0.0.0.0"), mHubPort(5555), mNodeIP("127.0.0.1"), 
    mSessionHanlderServer(std::make_unique<SessionHandler>(std::make_shared<rpc::server>(mHubIP, mHubPort))),
    mSessionHanlderClient(std::make_unique<SessionHandler>(std::make_shared<rpc::client>(mNodeIP, mHubPort)))
{}



GlobalContext & GlobalContext::Instance()
{
    static GlobalContext instance;
    return instance;
}


SessionHandler & GlobalContext::GetSessionHandlerServer()
{
    return *mSessionHanlderServer;
}


SessionHandler & GlobalContext::GetSessionHandlerClient()
{
    return *mSessionHanlderClient;
}