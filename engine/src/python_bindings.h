#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "hub.h"
#include <Column/Column.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(interpreter) {
    using namespace boost::python;
    def("InitialiseHub", &InitialiseHub);
    class_<Column<double>>("DoubleColumn")
        .def("Print", &Column<double>::Print)
        .def("LoadData", &Column<double>::LoadData)
        .def("AddElement", &Column<double>::AddElement)
        .def("GetElement", &Column<double>::GetElement)
        .def("Sum", &Column<double>::Sum)
        .def("Count", &Column<double>::Count)
        .def("Fetch", &Column<double>::Fetch)
        .def("MomentI", &Column<double>::MomentI)
        .def("MomentII", &Column<double>::MomentII)
        .def("Stddev", &Column<double>::Stddev);

    class_<Column<float>>("FloatColumn")
        .def("Print", &Column<float>::Print)
        .def("LoadData", &Column<float>::LoadData)
        .def("AddElement", &Column<float>::AddElement)
        .def("GetElement", &Column<float>::GetElement)
        .def("Sum", &Column<float>::Sum)
        .def("Count", &Column<float>::Count)
        .def("Fetch", &Column<float>::Fetch)
        .def("MomentI", &Column<float>::MomentI)
        .def("MomentII", &Column<float>::MomentII)
        .def("Stddev", &Column<float>::Stddev);

    class_<Column<int>>("IntColumn")
        .def("Print", &Column<int>::Print)
        .def("LoadData", &Column<int>::LoadData)
        .def("AddElement", &Column<int>::AddElement)
        .def("GetElement", &Column<int>::GetElement)
        .def("Sum", &Column<int>::Sum)
        .def("Count", &Column<int>::Count)
        .def("Fetch", &Column<int>::Fetch)
        .def("MomentI", &Column<int>::MomentI)
        .def("MomentII", &Column<int>::MomentII)
        .def("Stddev", &Column<int>::Stddev);
}
