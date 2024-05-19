#include "ParameterControllerHub.h"
#include <Tools/Utility.h>
#include <sstream>

void ParameterControllerHub::LoadHubConnectionInfo( const std::vector<std::string>& rpcConnectionInfo,
                                                    const std::vector<std::string>& tcpConnectionInfo )
{
    for ( const auto& info : rpcConnectionInfo )
    {
        mServerInfo.push_back( info );
    }

    for ( const auto& info : tcpConnectionInfo )
    {
        mTcpPorts.push_back( std::stoi( info ) );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    util::PrintVector( mServerInfo, "ServerInfo: " );
}

const std::vector<std::string>& ParameterControllerHub::GetServerInfo() const
{
    return mServerInfo;
}

const std::vector<uint>& ParameterControllerHub::GetTcpPorts() const
{
    return mTcpPorts;
}

size_t ParameterControllerHub::GetNumberOfNodes()
{
    return mServerInfo.size();
}
