cmake_minimum_required(VERSION 3.0.0)


ADD_SUBDIRECTORY(Networking)
ADD_SUBDIRECTORY(Column)
ADD_SUBDIRECTORY(Aggregations)

add_executable(server server.cpp)
target_link_libraries(server PUBLIC Networking)

add_executable(client client.cpp)
target_link_libraries(client PUBLIC Networking)
