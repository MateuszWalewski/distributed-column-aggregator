set(SOURCE_FILES ConfigurationManager.cpp)
add_library(ConfigurationManager STATIC ${SOURCE_FILES})

target_link_libraries(ConfigurationManager PRIVATE Networking)
target_include_directories(ConfigurationManager INTERFACE .)
