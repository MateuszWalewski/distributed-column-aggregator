#include <boost/test/unit_test.hpp>

#include "src/ColumnOperationsNode/ColumnOperationsNode.h"

BOOST_AUTO_TEST_SUITE( Aggregations )

BOOST_AUTO_TEST_CASE( AllocateAndAggregate_test3 )
{
    auto result = calcs::AllocateAndAggregate( 3, 2 );

    BOOST_TEST( result == 6 );
}

BOOST_AUTO_TEST_SUITE_END()