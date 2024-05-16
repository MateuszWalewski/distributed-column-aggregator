#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unistd.h>

#include <Column/Column.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterController/ParameterControllerHub.h>
#include <Tools/Utility.h>

#include <rpc/client.h>

#include <boost/python.hpp>

using RPCClientHandlers = std::vector<std::shared_ptr<rpc::client>>;

void InitialiseDB()
{
    auto rpcConnectionInfo = util::SplitStringToVector( std::getenv( "RPC_CONNECTIONS" ) );
    auto tcpConnectionInfo = util::SplitStringToVector( std::getenv( "TCP_CONNECTIONS" ) );
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    pCInstance.LoadHubConnectionInfo( rpcConnectionInfo, tcpConnectionInfo );
    pCInstance.PrintHubConnectionInfo();

    RPCClientHandlers rpcClientHandlers;
    auto serverInfo = pCInstance.GetServerInfo();

    for ( const auto& info : serverInfo )
    {
        std::istringstream iss( info );
        std::string ipAddress, port;

        std::getline( iss, ipAddress, ':' );
        std::getline( iss, port );

        rpcClientHandlers.push_back( std::make_shared<rpc::client>( ipAddress, std::stoi( port ) ) );
    }

    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.SetRPCClientInfo( rpcClientHandlers );
}

BOOST_PYTHON_MODULE( interpreter )
{
    using namespace boost::python;
    def( "InitialiseDB", &InitialiseDB );

    class_<Column<double>>( "DoubleColumn" )
        .def( "Print", &Column<double>::Print )
        .def( "LoadData", &Column<double>::LoadData )
        .def( "AddElement", &Column<double>::AddElement )
        .def( "GetElement", &Column<double>::GetElement )
        .def( "Sum", &Column<double>::Sum )
        .def( "Count", &Column<double>::Count )
        .def( "Fetch", &Column<double>::Fetch )
        .def( "MomentI", &Column<double>::MomentI )
        .def( "MomentII", &Column<double>::MomentII )
        .def( "Stddev", &Column<double>::Stddev );

    class_<Column<float>>( "FloatColumn" )
        .def( "Print", &Column<float>::Print )
        .def( "LoadData", &Column<float>::LoadData )
        .def( "AddElement", &Column<float>::AddElement )
        .def( "GetElement", &Column<float>::GetElement )
        .def( "Sum", &Column<float>::Sum )
        .def( "Count", &Column<float>::Count )
        .def( "Fetch", &Column<float>::Fetch )
        .def( "MomentI", &Column<float>::MomentI )
        .def( "MomentII", &Column<float>::MomentII )
        .def( "Stddev", &Column<float>::Stddev );

    class_<Column<int>>( "IntColumn" )
        .def( "Print", &Column<int>::Print )
        .def( "LoadData", &Column<int>::LoadData )
        .def( "AddElement", &Column<int>::AddElement )
        .def( "GetElement", &Column<int>::GetElement )
        .def( "Sum", &Column<int>::Sum )
        .def( "Count", &Column<int>::Count )
        .def( "Fetch", &Column<int>::Fetch )
        .def( "MomentI", &Column<int>::MomentI )
        .def( "MomentII", &Column<int>::MomentII )
        .def( "Stddev", &Column<int>::Stddev );
}
