#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unistd.h>

#include "Column/Column.h"
#include "ParameterController/ParameterControllerHub.h"
#include "Tools/Utility.h"

#include <boost/python.hpp>

void LoadConnectionDetails( std::string connectionDetails )
{
    PCTRL().LoadHubConnectionInfo( SplitStringToVector( connectionDetails ) );
    PCTRL().PrintHubConnectionInfo();
}

BOOST_PYTHON_FUNCTION_OVERLOADS( LoadConnectionDetailsP, LoadConnectionDetails, 1, 1 )

BOOST_PYTHON_MODULE( interpreter )
{
    using namespace boost::python;
    def( "LoadConnectionDetails", &LoadConnectionDetails, LoadConnectionDetailsP( args( "args" ) ) );

    class_<Column<double>>( "DoubleColumn" )
        .def( "Print", &Column<double>::Print )
        .def( "LoadData", &Column<double>::LoadData )
        .def( "Sum", &Column<double>::Sum );

    class_<Column<int>>( "IntColumn" )
        .def( "Print", &Column<int>::Print )
        .def( "LoadData", &Column<int>::LoadData )
        .def( "Sum", &Column<int>::Sum );
}
