#pragma once
#include <string>
#include <vector>

#define PCTRL() ParameterController::Instance()

class ParameterController
{
private:
    ParameterController();

    bool mIsHub;
    std::vector<std::string> mHubIPs;
    std::vector<std::string> mHubPorts;

    std::string mNodeIP;
    std::string mNodePort;

public:
    static ParameterController & Instance();

    void LoadParameter( std::string parameter );

    void LoadHubConnectionInfo( char * args[], int argc );

    void LoadNodeConnectionInfo( char * args[] );

    void PrintHubConnectionInfo();

    void PrintNodeConnectionInfo();

    bool IsHub();
};