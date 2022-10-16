#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unistd.h>

#include "Aggregations/SimpleAggsDist.h"
#include "Column/Column.h"
#include "ParameterController/ParameterControllerHub.h"

#include <boost/python.hpp>

void ConnectToNodes( std::string connectionDetails )
{
    PCTRL().LoadHubConnectionInfo( SplitStringToVector( connectionDetails ) );
    PCTRL().PrintHubConnectionInfo();
}

BOOST_PYTHON_FUNCTION_OVERLOADS( ConnectToNodesP, ConnectToNodes, 1, 1 )
BOOST_PYTHON_FUNCTION_OVERLOADS( LoadDataP, LoadData, 1, 1 )

BOOST_PYTHON_MODULE( interpreter )
{
    using namespace boost::python;
    def( "ConnectToNodes", &ConnectToNodes, ConnectToNodesP( args( "args" ) ) );

    class_<Column<double>>( "DoubleColumn" )
        .def( "AddElement", &Column<double>::AddElement )
        .def( "Print", &Column<double>::Print )
        .def( "LoadData", &Column<double>::LoadData )
        .def( "Sum", &Column<double>::Sum );

    class_<Column<int>>( "IntColumn" )
        .def( "AddElement", &Column<int>::AddElement )
        .def( "Print", &Column<int>::Print )
        .def( "LoadData", &Column<int>::LoadData )
        .def( "Sum", &Column<int>::Sum );
}
