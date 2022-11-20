add_library(
    Factory
    STATIC
    Factory.h
    Factory.cpp)

target_link_libraries(Factory PUBLIC ColumnEngine)
