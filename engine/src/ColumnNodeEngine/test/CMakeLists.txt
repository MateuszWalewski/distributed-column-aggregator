set(TEST_FILES ColumnNodeEngineTest.cpp)

add_executable(ColumnNodeEngineTest ${TEST_FILES})

target_link_libraries(ColumnNodeEngineTest PRIVATE GTest::gtest_main ColumnNodeEngine)

add_test(NAME ColumnNodeEngineTestUT
        COMMAND ColumnNodeEngineTest --gtest_color=yes
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
