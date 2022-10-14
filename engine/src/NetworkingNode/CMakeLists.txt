add_library(
    NetworkingNode
    STATIC
    SessionHandlerNode.h
    SessionHandlerNode.cpp)

find_package(Threads REQUIRED)

target_link_libraries(NetworkingNode PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT} PRIVATE ContainerAggregations)
#target_link_libraries(Networking rpc)

