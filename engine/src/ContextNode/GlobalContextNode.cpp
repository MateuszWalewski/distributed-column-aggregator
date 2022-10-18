#include "GlobalContextNode.h"
#include "ParameterControllerNode/ParameterControllerNode.h"
#include <iostream>

GlobalContextNode::GlobalContextNode()
{
    mRpcManager = std::make_shared<RPCManager>();
    mRpcManager->SetRPCServer( std::make_shared<rpc::server>( PCTRL().GetNodeIP(), std::stoi( PCTRL().GetNodePort() ) ) );

    std::cout << "GlobalContextNode called" << std::endl;
}

GlobalContextNode & GlobalContextNode::Instance()
{
    static GlobalContextNode instance;
    return instance;
}

RPCManager & GlobalContextNode::GetRPCManager()
{
    return *mRpcManager;
}
