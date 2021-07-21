cmake_minimum_required(VERSION 3.0.0)
#project(distDB)

#SET(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

ADD_SUBDIRECTORY(Networking)
#find_package(rpclib REQUIRED)
#find_package(Threads REQUIRED)

add_executable(server server.cpp)
target_link_libraries(server PUBLIC Networking)
#set_property(TARGET server PROPERTY CXX_STANDARD 14)

#add_executable(server2 server2.cpp)
#target_link_libraries(server2 PUBLIC Networking)

add_executable(client client.cpp)
target_link_libraries(client PUBLIC Networking)
#set_property(TARGET client PROPERTY CXX_STANDARD 14)
