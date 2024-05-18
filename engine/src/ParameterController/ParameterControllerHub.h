#pragma once
#include <string>
#include <vector>

class ParameterControllerHub
{
public:
    ParameterControllerHub() = default;

    void LoadHubConnectionInfo( const std::vector<std::string>& rpcConnectionInfo,
                                const std::vector<std::string>& tcpConnectionInfo );
    void PrintHubConnectionInfo();

    const std::vector<std::string>& GetServerInfo() const;
    const std::vector<uint>& GetNodesTcpPorts() const;
    size_t GetNumberOfNodes();

private:
    std::vector<std::string> mServerInfo;
    std::vector<uint> mTcpPorts;
};
