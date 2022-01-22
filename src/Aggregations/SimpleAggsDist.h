#pragma once

#include "Context/GlobalContextHub.h"
#include "SimpleAggs.h"
#include <iostream>
#include <numeric>
#include <vector>

namespace calcs
{
template <typename T> T AllocateAndAggregateDist( std::vector<T> container )
{
    std::string funcName = "AllocateAndAggregate" + std::string( typeid( T ).name() );

    // distribute data before sending it on nodes
    // consider adding Distribution class taking std::vector<T> container and
    // choping it on fragments according to number of nodes
    // with data distributed using predefined modes like:
    // - hash
    // - roundrobin
    // - etc.

    auto results = CTX().GetSessionHandler().CallRPCMethod( funcName, container );

    for ( auto & x : results )
    {
        std::cout << x << std::endl;
    }

    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
}
} // namespace calcs
