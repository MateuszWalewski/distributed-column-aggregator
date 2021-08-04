#include "SimpleAggsDist.h"
#include "SimpleAggs.h"
#include <vector>
#include <iostream>

#include "../Context/GlobalContext.h"

namespace calcs
{
    int AllocateAndAggregateDist(int containerSize, int fillValue)
    {
        // TODO: make session available here, for ex. from some singleton class storing SessionHandler
        auto result = GlobalContext::Instance(true).GetSessionHandler().GetHub()->call("AllocateAndAggregate", containerSize, fillValue).as<int>();

        // TODO: make the funtion making calls in parallel on many nodes 
        // (simple parallelism in C++ with saving res to vector will be probably enough)

        return result;
    }
}  // namespace calcs
