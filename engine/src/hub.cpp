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
//#include <TCPChannel/TCPServer.h>
#include <Tools/Utility.h>

#include <rpc/client.h>

#include <boost/python.hpp>

using RPCClientHandlers = std::vector<std::shared_ptr<rpc::client>>;

void LoadDependencies( std::string connectionDetails )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    pCInstance.LoadHubConnectionInfo( util::SplitStringToVector( connectionDetails ) );
    pCInstance.PrintHubConnectionInfo();

    RPCClientHandlers rpcClientHandlers;
    rpcClientHandlers.resize( pCInstance.GetNodesPorts().size() );

    for ( size_t i = 0; i < rpcClientHandlers.size(); i++ )
    {
        rpcClientHandlers[i] =
            std::make_shared<rpc::client>( pCInstance.GetNodesIPs()[i], std::stoi( pCInstance.GetNodesPorts()[i] ) );
    }

    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.SetRPCClientInfo( rpcClientHandlers );
    // TCPServer tcpServer;
}

BOOST_PYTHON_FUNCTION_OVERLOADS( LoadDependenciesP, LoadDependencies, 1, 1 )

BOOST_PYTHON_MODULE( interpreter )
{
    using namespace boost::python;
    def( "LoadDependencies", &LoadDependencies, LoadDependenciesP( args( "args" ) ) );

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
