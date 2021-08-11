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

void ParameterController::LoadParameter( std::string parameter )
{
    mIsHub = parameter == "hub";
}

// maybe could be done better than passing raw char*[] ?
void ParameterController::LoadHubConnectionInfo( char * args[], int argc )
{
    for ( int i = 2; i < argc / 2 + 1; i++ )
    {
        // add checker/assert
        mHubIPs.push_back( std::string( args[2 * i - 2] ) );
        // add checker/assert
        mHubPorts.push_back( std::string( args[2 * i - 1] ) );
    }
}

// maybe could be done better than passing raw char*[] ?
void ParameterController::LoadNodeConnectionInfo( char * args[] )
{
    // add checker/assert
    mNodeIP = std::string( args[2] );
    // add checker/assert
    mNodePort = std::string( args[3] );
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
    std::cout << "mNodeIP: " << mNodeIP << std::endl;
    std::cout << "mNodePort: " << mNodePort << std::endl;
}

bool ParameterController::IsHub()
{
    return mIsHub;
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
    return mNodeIP;
}

std::string ParameterController::GetNodePort()
{
    return mNodePort;
}
