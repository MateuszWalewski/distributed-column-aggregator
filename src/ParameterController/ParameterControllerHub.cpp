#include "ParameterControllerHub.h"

#include <iostream>

ParameterControllerHub::ParameterControllerHub()
{
}

ParameterControllerHub & ParameterControllerHub::Instance()
{
    static ParameterControllerHub instance;
    return instance;
}

// maybe could be done better than passing raw char*[] ?
void ParameterControllerHub::LoadHubConnectionInfo( char * args[], int argc )
{
    for ( int i = 1; i < argc / 2 + 1; i++ )
    {
        // add checker/assert
        mNodesIPs.push_back( std::string( args[2 * i - 1] ) );
        // add checker/assert
        mNodesPorts.push_back( std::string( args[2 * i] ) );
    }
}

void ParameterControllerHub::PrintHubConnectionInfo()
{
    for ( auto & x : mNodesIPs )
    {
        std::cout << "mNodesIPs: " << x << std::endl;
    }

    for ( auto & x : mNodesPorts )
    {
        std::cout << "mNodesPorts: " << x << std::endl;
    }
}


std::vector<std::string> ParameterControllerHub::GetNodesIPs()
{
    return mNodesIPs;
}

std::vector<std::string> ParameterControllerHub::GetNodesPorts()
{
    return mNodesPorts;
}

