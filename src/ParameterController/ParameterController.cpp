#include "ParameterController.h"

#include <iostream>

ParameterController::ParameterController()
{
}

ParameterController & ParameterController::Instance()
{
    static ParameterController instance;
    return instance;
}

// maybe could be done better than passing raw char*[] ?
void ParameterController::LoadHubConnectionInfo( char * args[], int argc )
{
    for ( int i = 1; i < argc / 2 + 1; i++ )
    {
        // add checker/assert
        mHubIPs.push_back( std::string( args[2 * i - 1] ) );
        // add checker/assert
        mHubPorts.push_back( std::string( args[2 * i] ) );
    }
}

// maybe could be done better than passing raw char*[] ?
void ParameterController::LoadNodeConnectionInfo( char * args[] )
{
    // add checker/assert
    mNodePort = std::string( args[1] );
}

void ParameterController::PrintHubConnectionInfo()
{
    for ( auto & x : mHubIPs )
    {
        std::cout << "mHubIPs: " << x << std::endl;
    }

    for ( auto & x : mHubPorts )
    {
        std::cout << "mHubPorts: " << x << std::endl;
    }
}

void ParameterController::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << mNodePort << std::endl;
}

std::vector<std::string> ParameterController::GetHubIPs()
{
    return mHubIPs;
}

std::vector<std::string> ParameterController::GetHubPorts()
{
    return mHubPorts;
}

std::string ParameterController::GetNodeIP()
{
    return "0.0.0.0";
}

std::string ParameterController::GetNodePort()
{
    return mNodePort;
}
