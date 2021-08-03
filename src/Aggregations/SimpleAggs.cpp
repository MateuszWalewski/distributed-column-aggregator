#include "SimpleAggs.h"
#include <vector>
#include <iostream>

namespace calcs
{
    int AllocateAndAggregate(int containerSize, int fillValue)
    {
        std::vector<int> container (containerSize, fillValue);
        // Make it as a separate function in Tools module
        for (auto & x : container)
        {
            std::cout << x << std::endl;
        } 
        return std::accumulate(container.begin(), container.end(), 0);
    }
}  // namespace calcs
