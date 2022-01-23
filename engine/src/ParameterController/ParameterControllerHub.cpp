#include "ParameterControllerHub.h"
#include "Tools/Utility.h"

ParameterControllerHub::ParameterControllerHub()
{
}

ParameterControllerHub & ParameterControllerHub::Instance()
{
    static ParameterControllerHub instance;
    return instance;
}

void ParameterControllerHub::LoadHubConnectionInfo( std::vector<std::string> connInfo )
{
    for ( int i = 0; i < connInfo.size() / 2; i++ )
    {
        // add checker/assert
        mNodesIPs.push_back( connInfo[2 * i] );
        // add checker/assert
        mNodesPorts.push_back( connInfo[2 * i + 1] );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    PrintVector( mNodesIPs, "mNodesIPs" );
    PrintVector( mNodesPorts, "mNodesPorts" );
}

std::vector<std::string> ParameterControllerHub::GetNodesIPs()
{
    return mNodesIPs;
}

std::vector<std::string> ParameterControllerHub::GetNodesPorts()
{
    return mNodesPorts;
}

size_t ParameterControllerHub::GetNumberOfNodes()
{
    return mNodesPorts.size();
}
