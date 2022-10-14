#include "GlobalContextNode.h"

#include <iostream>

GlobalContextNode::GlobalContextNode()
{
    mSessionHandler = std::make_shared<SessionHandlerNode>(
        std::make_shared<rpc::server>( PCTRL().GetNodeIP(), std::stoi( PCTRL().GetNodePort() ) ) );

    std::cout << "GlobalContextNode called" << std::endl;
}

GlobalContextNode & GlobalContextNode::Instance()
{
    static GlobalContextNode instance;
    return instance;
}

SessionHandlerNode & GlobalContextNode::GetSessionHandler()
{
    return *mSessionHandler;
}
