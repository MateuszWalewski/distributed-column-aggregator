#include <boost/test/unit_test.hpp>

#include "src/Aggregations/SimpleAggsDist.h"
#include "src/ParameterController/ParameterController.h"

BOOST_AUTO_TEST_SUITE( AggregationsDist )

BOOST_AUTO_TEST_CASE( AllocateAndAggregate_test3 )
{
    PCTRL().LoadParameter( "hub" );
    auto result = calcs::AllocateAndAggregateDist( 3, 2 );

    BOOST_TEST( result == 6 );
}

BOOST_AUTO_TEST_SUITE_END()