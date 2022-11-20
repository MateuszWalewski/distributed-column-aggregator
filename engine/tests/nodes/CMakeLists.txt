add_executable(test_unit
    test_setup.cpp
    test_one.cpp
    test_two.cpp
)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(test_unit Boost::unit_test_framework ColumnOperationsNode)

target_compile_definitions(test_unit PUBLIC BOOST_TEST_DYN_LINK)