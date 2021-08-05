#include "SimpleAggsDist.h"
#include "SimpleAggs.h"
#include <vector>
#include <iostream>

#include "Context/GlobalContext.h"

namespace calcs
{
    int AllocateAndAggregateDist(int containerSize, int fillValue)
    {
        // TODO: make the funtion making calls in parallel on many nodes 
        // (simple parallelism in C++ with saving res to vector will be probably enough)

        return CTX().GetSessionHandler().CallRPCMethod("AllocateAndAggregate", containerSize, fillValue);
    }
}  // namespace calcs
