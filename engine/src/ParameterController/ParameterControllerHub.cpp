#include "ParameterControllerHub.h"
#include <Tools/Utility.h>

void ParameterControllerHub::LoadHubConnectionInfo( const std::vector<std::string>& connectionInfo )
{
    for ( int i = 0; i < static_cast<int>( connectionInfo.size() ) / 2; i++ )
    {
        mNodesIPs.push_back( connectionInfo[2 * i] );
        mNodesPorts.push_back( connectionInfo[2 * i + 1] );
        /// TODO: take TCP port value from ENV param instead of hardcoded one
        mNodesTCPPorts.push_back( std::stoi( connectionInfo[2 * i + 1] ) + 27 );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    util::PrintVector( mNodesIPs, "mNodesIPs" );
    util::PrintVector( mNodesPorts, "mNodesPorts" );
}

const std::vector<std::string>& ParameterControllerHub::GetNodesIPs() const
{
    return mNodesIPs;
}

const std::vector<std::string>& ParameterControllerHub::GetNodesPorts() const
{
    return mNodesPorts;
}

const std::vector<uint>& ParameterControllerHub::GetNodesTCPPorts() const
{
    return mNodesTCPPorts;
}

size_t ParameterControllerHub::GetNumberOfNodes()
{
    return mNodesPorts.size();
}
