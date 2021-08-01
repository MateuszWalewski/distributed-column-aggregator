add_library(
    Networking
    SHARED
    SessionHandler.h
    SessionHandler.cpp)

find_package(Threads REQUIRED)

target_link_libraries(Networking PUBLIC rpc ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(Networking rpc)

#install(TARGETS Networking DESTINATION lib)
#install(FILES SessionHandler.h DESTINATION include)
