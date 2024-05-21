#include "ParameterControllerNode.h"
#include <boost/lexical_cast.hpp>

#include <iostream>

void ParameterControllerNode::LoadNodeConnectionInfo( const char* rpcPort, const char* tcpPort )
{
    try
    {
        _rpcPort = boost::lexical_cast<uint>( rpcPort );
        _tcpPort = boost::lexical_cast<uint>( tcpPort );
    }
    catch ( const boost::bad_lexical_cast& e )
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ParameterControllerNode::PrintNodeConnectionInfo()
{
    std::cout << "mNodePort: " << _tcpPort << std::endl;
}

uint ParameterControllerNode::GetRpcPort()
{
    return _rpcPort;
}

uint ParameterControllerNode::GetTcpPort()
{
    return _tcpPort;
}
