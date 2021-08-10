#include <boost/test/unit_test.hpp>

#include "src/Aggregations/SimpleAggs.h"

BOOST_AUTO_TEST_SUITE( Aggregations )

BOOST_AUTO_TEST_CASE( AllocateAndAggregate_test )
{
    auto result = calcs::AllocateAndAggregate( 4, 6 );

    BOOST_TEST( result == 24 );
}

BOOST_AUTO_TEST_CASE( AllocateAndAggregate_test2 )
{
    auto result = calcs::AllocateAndAggregate( 7, 8 );

    BOOST_TEST( result == 56 );
}

BOOST_AUTO_TEST_SUITE_END()