add_library(
    Networking
    STATIC
    SessionHandlerHub.h
    SessionHandlerHub.cpp
    SessionHandlerNode.h
    SessionHandlerNode.cpp)

find_package(Threads REQUIRED)

target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT} PRIVATE ContainerAggregations)
#target_link_libraries(Networking rpc)

