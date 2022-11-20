add_library(
    Networking
    STATIC
    RPCManager.h
    RPCManager.cpp
    )

find_package(Threads REQUIRED)

target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(Networking rpc)

