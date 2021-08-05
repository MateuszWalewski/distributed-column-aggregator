#include <boost/test/unit_test.hpp> 

#include "src/Aggregations/SimpleAggsDist.h"
#include "src/ParameterController/ParameterController.h"

BOOST_AUTO_TEST_SUITE(AggregationsDist)

BOOST_AUTO_TEST_CASE(AllocateAndAggregate_test)
{
    PCTRL().LoadParameter("hub");
    auto result = calcs::AllocateAndAggregateDist(4,6);

    BOOST_TEST(result == 24); 
}

BOOST_AUTO_TEST_CASE(AllocateAndAggregate_test2)
{
    PCTRL().LoadParameter("hub");
    auto result = calcs::AllocateAndAggregateDist(7,8);

    BOOST_TEST(result == 56); 
}

BOOST_AUTO_TEST_SUITE_END()