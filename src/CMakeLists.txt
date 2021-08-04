cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(Aggregations)
ADD_SUBDIRECTORY(Context)

add_executable(server server.cpp)
# TODO: Look on that. It is growing more and more - maybe there is some wiser method for doing that ? 
target_link_libraries(server PUBLIC Networking ContainerAggregations ContainerAggregationsDist)

add_executable(client client.cpp)
target_link_libraries(client PUBLIC Networking ContainerAggregations ContainerAggregationsDist)

# TODO: ditto
INSTALL(TARGETS server client RUNTIME DESTINATION bin)
INSTALL(TARGETS Networking LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregations LIBRARY DESTINATION lib)
INSTALL(TARGETS ContainerAggregationsDist LIBRARY DESTINATION lib)
