#pragma once
#include <string>
#include <vector>

class ParameterControllerNode
{
public:
    ParameterControllerNode() = default;

    void LoadHubConnectionInfo( char* args[], int argc );

    void LoadNodeConnectionInfo( char* args[] );

    void PrintHubConnectionInfo();

    void PrintNodeConnectionInfo();

    std::string GetNodeIP();
    std::string GetNodePort();
    uint GetNodeTCPPort();

private:
    uint mNodeTCPPort;
    std::string mNodePort;
};