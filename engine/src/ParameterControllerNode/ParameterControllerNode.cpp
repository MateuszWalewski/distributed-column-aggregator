#include "ParameterControllerNode.h"

#include <iostream>

void ParameterControllerNode::LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort )
{
    _rpcPort = std::stoi( rpcPort );
    _tcpPort = std::stoi( tcpPort );
}

void ParameterControllerNode::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << _tcpPort << std::endl;
}

uint ParameterControllerNode::GetRpcPort()
{
    return _rpcPort;
}

uint ParameterControllerNode::GetTcpPort()
{
    return _tcpPort;
}
