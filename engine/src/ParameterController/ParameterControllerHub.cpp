#include "ParameterControllerHub.h"
#include <Tools/Utility.h>
#include <sstream>

void ParameterControllerHub::LoadHubConnectionInfo( const std::vector<std::string>& rpcConnectionInfo,
                                                    const std::vector<std::string>& tcpConnectionInfo )
{
    for ( const auto& info : rpcConnectionInfo )
    {
        _serverInfo.push_back( info );
    }

    for ( const auto& info : tcpConnectionInfo )
    {
        _tcpPorts.push_back( std::stoi( info ) );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    util::PrintVector( _serverInfo, "ServerInfo: " );
}

const std::vector<std::string>& ParameterControllerHub::GetServerInfo() const
{
    return _serverInfo;
}

const std::vector<uint>& ParameterControllerHub::GetTcpPorts() const
{
    return _tcpPorts;
}

size_t ParameterControllerHub::GetNumberOfNodes()
{
    return _serverInfo.size();
}
