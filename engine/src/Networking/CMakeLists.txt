set(SOURCE_FILES RPCManager.cpp)
add_library(Networking STATIC ${SOURCE_FILES})

find_package(Threads REQUIRED)

target_link_libraries(Networking PRIVATE rpc ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(Networking INTERFACE .)



