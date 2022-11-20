#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unistd.h>

#include "Column/Column.h"
#include "Loki/Singleton.h"
#include "Networking/RPCManager.h"
#include "ParameterController/ParameterControllerHub.h"
#include "Tools/Utility.h"

#include "rpc/client.h"

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
        .def( "Sum", &Column<double>::Sum );

    class_<Column<float>>( "FloatColumn" )
        .def( "Print", &Column<float>::Print )
        .def( "LoadData", &Column<float>::LoadData )
        .def( "AddElement", &Column<float>::AddElement )
        .def( "Sum", &Column<float>::Sum );

    class_<Column<int>>( "IntColumn" )
        .def( "Print", &Column<int>::Print )
        .def( "LoadData", &Column<int>::LoadData )
        .def( "AddElement", &Column<int>::AddElement )
        .def( "Sum", &Column<int>::Sum );
}
