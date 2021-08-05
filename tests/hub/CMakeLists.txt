add_executable(test_unit_dist
    test_setup.cpp
    test_one.cpp
    test_two.cpp
)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(test_unit_dist Boost::unit_test_framework ContainerAggregationsDist ParameterController)

target_compile_definitions(test_unit_dist PUBLIC BOOST_TEST_DYN_LINK)
