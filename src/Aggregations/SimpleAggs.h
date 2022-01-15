#pragma once

#include <numeric>
#include <vector>

#include <iostream>

namespace calcs
{
template <typename T> T AllocateAndAggregate( std::vector<T> container )
{
    // Make it as a separate function in Tools module
    for ( auto & x : container )
    {
        std::cout << x << std::endl;
    }
    return std::accumulate( container.begin(), container.end(), static_cast<T>( 0 ) );
}
} // namespace calcs
