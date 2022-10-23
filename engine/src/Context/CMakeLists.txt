add_library(
    GlobalContext
    STATIC
    GlobalContextHub.h
    GlobalContextHub.cpp
    )

target_link_libraries(GlobalContext PUBLIC ColumnEngine Networking)
