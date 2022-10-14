add_library(
    Networking
    STATIC
    SessionHandlerHub.h
    SessionHandlerHub.cpp
    )

find_package(Threads REQUIRED)

target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT} PRIVATE ContainerAggregationsDist)
#target_link_libraries(Networking rpc)

