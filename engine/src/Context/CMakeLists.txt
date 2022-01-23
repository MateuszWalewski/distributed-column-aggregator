add_library(
    GlobalContext
    STATIC
    GlobalContextHub.h
    GlobalContextHub.cpp
    GlobalContextNode.h
    GlobalContextNode.cpp)

target_link_libraries(GlobalContext PUBLIC Networking)
