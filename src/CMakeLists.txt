cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include_directories(".")

ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(Aggregations)
ADD_SUBDIRECTORY(Context)
ADD_SUBDIRECTORY(ParameterController)

add_executable(miniDBNode miniDBNode.cpp)
# TODO: Look on that. It is growing more and more - maybe there is some wiser method for doing that ? 
target_link_libraries(miniDBNode PUBLIC ParameterController GlobalContext ContainerAggregations ContainerAggregationsDist)

add_executable(miniDBHub miniDBHub.cpp)
target_link_libraries(miniDBHub PUBLIC ParameterController GlobalContext ContainerAggregations ContainerAggregationsDist)

# TODO: ditto
INSTALL(TARGETS miniDBNode miniDBHub RUNTIME DESTINATION bin)
INSTALL(TARGETS GlobalContext LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregations LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregationsDist LIBRARY DESTINATION lib)
INSTALL(TARGETS ParameterController LIBRARY DESTINATION lib)
