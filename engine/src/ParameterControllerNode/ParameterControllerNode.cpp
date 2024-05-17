#include "ParameterControllerNode.h"

#include <iostream>

void ParameterControllerNode::LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort )
{
    mRPCPort = std::stoi( rpcPort );
    mTCPPort = std::stoi( tcpPort );
}

void ParameterControllerNode::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << mRPCPort << std::endl;
}

uint ParameterControllerNode::GetRPCPort()
{
    return mRPCPort;
}

uint ParameterControllerNode::GetTCPPort()
{
    return mTCPPort;
}
