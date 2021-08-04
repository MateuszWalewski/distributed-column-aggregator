#include "GlobalContext.h"
#include <iostream>


GlobalContext::GlobalContext(bool hub) : mHubIP("0.0.0.0"), mHubPort(5555), mNodeIP("127.0.0.1")//, 
//    mSessionHanlderServer(std::make_shared<SessionHandler>(std::make_shared<rpc::server>(mHubIP, mHubPort)))
   // mSessionHanlderClient(std::make_shared<SessionHandler>(std::make_shared<rpc::client>(mNodeIP, mHubPort)))
{
    mSessionHandler = hub ? std::make_shared<SessionHandler>(std::make_shared<rpc::client>(mNodeIP, mHubPort)) :
    std::make_shared<SessionHandler>(std::make_shared<rpc::server>(mHubIP, mHubPort));
}



GlobalContext & GlobalContext::Instance(bool hub)
{
    static GlobalContext instance(hub);
    return instance;
}


SessionHandler & GlobalContext::GetSessionHandler()
{
    return *mSessionHandler;
}



void GlobalContext::Hello()
{
    std::cout << "Hello I'm singleton!!!" << std::endl;
}