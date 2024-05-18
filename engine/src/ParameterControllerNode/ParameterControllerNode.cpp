#include "ParameterControllerNode.h"

#include <iostream>

void ParameterControllerNode::LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort )
{
    mRpcPort = std::stoi( rpcPort );
    mTcpPort = std::stoi( tcpPort );
}

void ParameterControllerNode::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << mRpcPort << std::endl;
}

uint ParameterControllerNode::GetRpcPort()
{
    return mRpcPort;
}

uint ParameterControllerNode::GetTcpPort()
{
    return mTcpPort;
}
