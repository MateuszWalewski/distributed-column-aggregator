enable_testing()

add_executable(
   unittests_node
   unittests_node.cpp
)
target_link_libraries(
   unittests_node
   GTest::gtest_main
   ColumnNodeEngine
)

include(GoogleTest)
gtest_discover_tests(unittests_node)


