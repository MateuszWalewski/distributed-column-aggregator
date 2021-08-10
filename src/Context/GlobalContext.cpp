#include "GlobalContext.h"

#include <iostream>

GlobalContext::GlobalContext() : mHubIP( "0.0.0.0" ), mHubPort( 5555 ), mNodeIP( "127.0.0.1" )
{
    mSessionHandler = PCTRL().IsHub() ? std::make_shared<SessionHandler>( std::make_shared<rpc::client>( mNodeIP, mHubPort ) )
                                      : std::make_shared<SessionHandler>( std::make_shared<rpc::server>( mHubIP, mHubPort ) );
}

GlobalContext & GlobalContext::Instance()
{
    static GlobalContext instance;
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