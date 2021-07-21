#cmake_minimum_required(VERSION 3.0.0)
#project(Networking)
add_library(
    Networking
    SHARED
    SessionHandler.h)

#target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Networking PUBLIC rpc)

#INSTALL(TARGETS GlobalContext DESTINATION lib)
#find_package(rpclib REQUIRED)

#set_property(TARGET server PROPERTY CXX_STANDARD 14)

