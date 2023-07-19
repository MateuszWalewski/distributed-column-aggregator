#include "ParameterControllerHub.h"
#include <Tools/Utility.h>

void ParameterControllerHub::LoadHubConnectionInfo( std::vector<std::string> connInfo )
{
    for ( int i = 0; i < (int) connInfo.size() / 2; i++ )
    {
        // add checker/assert
        mNodesIPs.push_back( connInfo[2 * i] );
        // add checker/assert
        mNodesPorts.push_back( connInfo[2 * i + 1] );
        ///TODO: take TCP port value from ENV param instead of hardcoded one
        mNodesTCPPorts.push_back( std::stoi( connInfo[2 * i + 1] ) + 27 );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    util::PrintVector( mNodesIPs, "mNodesIPs" );
    util::PrintVector( mNodesPorts, "mNodesPorts" );
}

std::vector<std::string> ParameterControllerHub::GetNodesIPs()
{
    return mNodesIPs;
}

std::vector<std::string> ParameterControllerHub::GetNodesPorts()
{
    return mNodesPorts;
}

std::vector<uint> ParameterControllerHub::GetNodesTCPPorts()
{
    return mNodesTCPPorts;
}

size_t ParameterControllerHub::GetNumberOfNodes()
{
    return mNodesPorts.size();
}
