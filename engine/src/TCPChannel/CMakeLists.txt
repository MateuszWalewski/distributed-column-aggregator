set(SOURCE_FILES TCPServer.cpp TCPClient.cpp)
add_library(TCPChannel STATIC ${SOURCE_FILES})


target_link_libraries(TCPChannel PRIVATE ConfigurationManager ${Boost_LIBRARIES})

target_include_directories(TCPChannel INTERFACE .)



