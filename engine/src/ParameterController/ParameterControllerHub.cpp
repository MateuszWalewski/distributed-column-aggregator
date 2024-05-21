#include "ParameterControllerHub.h"
#include <Tools/Utility.h>
#include <boost/lexical_cast.hpp>
#include <iostream>

void ParameterControllerHub::LoadHubConnectionInfo( const std::vector<std::string>& rpcConnectionInfo,
                                                    const std::vector<std::string>& tcpConnectionInfo )
{
    for ( const auto& info : rpcConnectionInfo )
    {
        _serverInfo.push_back( info );
    }

    for ( const auto& info : tcpConnectionInfo )
    {
        uint tcpPortNumber;
        try
        {
            tcpPortNumber = boost::lexical_cast<uint>( info );
        }
        catch ( const boost::bad_lexical_cast& e )
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        _tcpPorts.push_back( tcpPortNumber );
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
