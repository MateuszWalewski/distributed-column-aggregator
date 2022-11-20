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

    // check the form of returning value. Is it clean? Maybe method should be const?
    std::vector<std::string> GetHubIPs();
    std::vector<std::string> GetHubPorts();

    std::string GetNodeIP();
    std::string GetNodePort();

private:
    // check the correctnes of the naming convention i.e
    // on hub there are rather info about node detials than hub details
    std::vector<std::string> mHubIPs;
    std::vector<std::string> mHubPorts;

    std::string mNodePort;
};