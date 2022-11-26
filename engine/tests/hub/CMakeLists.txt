enable_testing()

add_executable(
   unittests
   unittests.cpp
)
target_link_libraries(
   unittests
   GTest::gtest_main ColumnEngine Networking ParameterController
)

include(GoogleTest)
gtest_discover_tests(unittests)
