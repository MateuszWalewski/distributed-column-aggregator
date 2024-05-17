#pragma once
#include <string>
#include <vector>

class ParameterControllerNode
{
public:
    ParameterControllerNode() = default;
    void LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort );
    void PrintNodeConnectionInfo();

    uint GetRPCPort();
    uint GetTCPPort();

private:
    uint mTCPPort;
    uint mRPCPort;
};
