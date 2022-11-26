set(TEST_FILES UtilityTest.cpp)

add_executable(UtilityTest ${TEST_FILES})

target_link_libraries(UtilityTest PRIVATE GTest::gtest_main ColumnNodeEngine)

add_test(NAME UtilityTestUT
        COMMAND UtilityTest --gtest_color=yes
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})