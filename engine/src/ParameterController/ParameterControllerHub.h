#pragma once
#include <string>
#include <vector>

class ParameterControllerHub
{
public:
    ParameterControllerHub() = default;

    void LoadHubConnectionInfo( const std::vector<std::string>& connInfo );

    void PrintHubConnectionInfo();

    const std::vector<std::string>& GetNodesIPs() const;
    const std::vector<std::string>& GetNodesPorts() const;
    const std::vector<uint>& GetNodesTCPPorts() const;
    size_t GetNumberOfNodes();

private:
    std::vector<std::string> mNodesIPs;
    std::vector<std::string> mNodesPorts;
    std::vector<uint> mNodesTCPPorts;
};
