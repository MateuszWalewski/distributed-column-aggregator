cmake_minimum_required(VERSION 3.0.0)
project(networking)

#find_package(rpclib REQUIRED)
find_package(Threads REQUIRED)

add_executable(server server.cpp)
target_link_libraries(server PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
#set_property(TARGET server PROPERTY CXX_STANDARD 14)

add_executable(client client.cpp)
target_link_libraries(client PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
#set_property(TARGET client PROPERTY CXX_STANDARD 14)
