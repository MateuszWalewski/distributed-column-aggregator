#pragma once
#include <string>
#include <vector>

class ParameterControllerNode
{
public:
    ParameterControllerNode() = default;
    void LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort );
    void PrintNodeConnectionInfo();

    uint GetRpcPort();
    uint GetTcpPort();

private:
    uint mTcpPort;
    uint mRpcPort;
};
