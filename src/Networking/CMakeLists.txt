add_library(
    Networking
    STATIC
    SessionHandler.h
    SessionHandler.cpp)

find_package(Threads REQUIRED)

target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(Networking rpc)

