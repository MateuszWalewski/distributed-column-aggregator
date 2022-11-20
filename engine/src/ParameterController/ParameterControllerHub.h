#pragma once
#include <string>
#include <vector>

class ParameterControllerHub
{
public:
    ParameterControllerHub() = default;

    void LoadHubConnectionInfo( std::vector<std::string> connInfo );

    void PrintHubConnectionInfo();

    // check the form of returning value. Is it clean? Maybe method should be const?
    std::vector<std::string> GetNodesIPs();
    std::vector<std::string> GetNodesPorts();
    size_t GetNumberOfNodes();

private:
    std::vector<std::string> mNodesIPs;
    std::vector<std::string> mNodesPorts;
};