cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

include_directories(".")

ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(NetworkingNode)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(Aggregations)
ADD_SUBDIRECTORY(AggregationsNode)
ADD_SUBDIRECTORY(Context)
ADD_SUBDIRECTORY(ColumnStorage)
ADD_SUBDIRECTORY(ContextNode)
ADD_SUBDIRECTORY(ParameterController)
ADD_SUBDIRECTORY(Tools)


# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
add_library(interpreter MODULE hub.cpp)

# Set up the libraries and header search paths for this target
target_link_libraries(interpreter PUBLIC ParameterController GlobalContext Networking ContainerAggregationsDist DataColumn Tools ${Boost_LIBRARIES} ${PYTHON_LIBRARIES}) 
target_include_directories(interpreter PRIVATE ${PYTHON_INCLUDE_DIRS})


add_executable(node node.cpp)
# TODO: Look on that. It is growing more and more - maybe there is some wiser method for doing that ? 
target_link_libraries(node PUBLIC ParameterController ColumnStorageNode GlobalContextNode NetworkingNode ContainerAggregations DataColumn Tools)

# add_executable(hub hub.cpp)
# target_link_libraries(hub PUBLIC ParameterController GlobalContext ContainerAggregations ContainerAggregationsDist Tools)

# TODO: ditto

INSTALL(TARGETS node RUNTIME DESTINATION bin)
INSTALL(TARGETS interpreter LIBRARY DESTINATION lib)
INSTALL(TARGETS GlobalContext LIBRARY DESTINATION lib)
INSTALL(TARGETS GlobalContextNode LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregations LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregationsDist LIBRARY DESTINATION lib)
INSTALL(TARGETS ParameterController LIBRARY DESTINATION lib)
INSTALL(TARGETS Tools LIBRARY DESTINATION lib)
