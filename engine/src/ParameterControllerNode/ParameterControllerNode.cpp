#include "ParameterControllerNode.h"

#include <iostream>

// maybe could be done better than passing raw char*[] ?
void ParameterControllerNode::LoadNodeConnectionInfo( char* args[] )
{
    // add checker/assert
    mNodePort = std::string( args[1] );
}

void ParameterControllerNode::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << mNodePort << std::endl;
}

// make it constexpr or sth?
std::string ParameterControllerNode::GetNodeIP()
{
    return "0.0.0.0";
}

std::string ParameterControllerNode::GetNodePort()
{
    return mNodePort;
}
