#pragma once

#include <numeric>
#include <vector>

#include <iostream>

namespace calcs
{
template <typename T> T AllocateAndAggregate( int containerSize, T fillValue )
{
    std::vector<T> container( containerSize, fillValue );
    // Make it as a separate function in Tools module
    for ( auto & x : container )
    {
        std::cout << x << std::endl;
    }
    return std::accumulate( container.begin(), container.end(), 0 );
}
} // namespace calcs
