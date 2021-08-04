add_library(
    GlobalContext
    STATIC
    GlobalContext.h
    GlobalContext.cpp)

target_link_libraries(GlobalContext PUBLIC Networking)
