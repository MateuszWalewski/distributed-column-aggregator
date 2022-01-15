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
    // TODO: make the funtion making calls in parallel on many nodes
    // (simple parallelism in C++ with saving res to vector will be probably enough)

    std::string funcName = "AllocateAndAggregate" + std::string( typeid( T ).name() );

    auto results = CTX().GetSessionHandler().CallRPCMethod( funcName, container );

    for ( auto & x : results )
    {
        std::cout << x << std::endl;
    }

    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
}
} // namespace calcs
