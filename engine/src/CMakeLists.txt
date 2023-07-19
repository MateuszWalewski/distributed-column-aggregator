cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)
find_package(TBB REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

include_directories(".")

ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(TCPChannel)
ADD_SUBDIRECTORY(Factory)
ADD_SUBDIRECTORY(FactoryNode)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(ColumnNode)
ADD_SUBDIRECTORY(ColumnEngine)
ADD_SUBDIRECTORY(ColumnNodeEngine)
ADD_SUBDIRECTORY(ColumnOperationsNode)
ADD_SUBDIRECTORY(ColumnNodeStorage)
ADD_SUBDIRECTORY(ParameterController)
ADD_SUBDIRECTORY(ParameterControllerNode)
ADD_SUBDIRECTORY(Tools)
ADD_SUBDIRECTORY(Loki)


# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
add_library(interpreter MODULE hub.cpp)

# Set up the libraries and header search paths for this target
target_link_libraries(interpreter PUBLIC ParameterController Networking DataColumn ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(interpreter PRIVATE ${PYTHON_INCLUDE_DIRS})


add_executable(node node.cpp)
target_link_libraries(node PUBLIC ParameterControllerNode Networking TCPChannel ColumnOperationsNode )

# TODO: ditto

INSTALL(TARGETS node RUNTIME DESTINATION bin)
INSTALL(TARGETS interpreter LIBRARY DESTINATION lib)
INSTALL(TARGETS ColumnOperationsNode LIBRARY DESTINATION lib)
INSTALL(TARGETS ParameterController LIBRARY DESTINATION lib)
INSTALL(TARGETS ParameterControllerNode LIBRARY DESTINATION lib)
INSTALL(TARGETS Tools LIBRARY DESTINATION lib)
