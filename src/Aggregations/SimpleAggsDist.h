#pragma once

#include <numeric>
#include <vector>

#include "Context/GlobalContextHub.h"
#include "SimpleAggs.h"

namespace calcs
{
template <typename T> 
T AllocateAndAggregateDist( int containerSize, T fillValue )
{
    // TODO: make the funtion making calls in parallel on many nodes
    // (simple parallelism in C++ with saving res to vector will be probably enough)

    auto results = CTX().GetSessionHandler().CallRPCMethod( "AllocateAndAggregate", containerSize, fillValue );

    return std::accumulate( results.begin(), results.end(), 0 );
}
} // namespace calcs
