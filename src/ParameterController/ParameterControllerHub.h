#pragma once
#include <string>
#include <vector>

#define PCTRL() ParameterControllerHub::Instance()

class ParameterControllerHub
{
private:
    ParameterControllerHub();

    std::vector<std::string> mNodesIPs;
    std::vector<std::string> mNodesPorts;


public:
    static ParameterControllerHub & Instance();

    void LoadHubConnectionInfo( char * args[], int argc );

    void PrintHubConnectionInfo();

    // check the form of returning value. Is it clean? Maybe method should be const?
    std::vector<std::string> GetNodesIPs();
    std::vector<std::string> GetNodesPorts();

    bool IsHub();
};