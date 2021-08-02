cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(Aggregations)

add_executable(server server.cpp)
target_link_libraries(server PUBLIC Networking)

add_executable(client client.cpp)
target_link_libraries(client PUBLIC Networking)

#check why its problem with share lib when uncommented
INSTALL(TARGETS server client RUNTIME DESTINATION bin)
INSTALL(TARGETS Networking LIBRARY DESTINATION lib)
