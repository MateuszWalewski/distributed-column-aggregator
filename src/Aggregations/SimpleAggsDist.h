#pragma once

#include <numeric>
#include <vector>

#include "Context/GlobalContextHub.h"
#include "SimpleAggs.h"
#include <type_traits>

namespace calcs
{
template <typename T> T AllocateAndAggregateDist( int containerSize, T fillValue )
{
    // TODO: make the funtion making calls in parallel on many nodes
    // (simple parallelism in C++ with saving res to vector will be probably enough)

    std::string funcName = "AllocateAndAggregate" + std::string( typeid( T ).name() );

    auto results = CTX().GetSessionHandler().CallRPCMethod( funcName, containerSize, fillValue );

    return std::accumulate( results.begin(), results.end(), 0 );
}
} // namespace calcs
