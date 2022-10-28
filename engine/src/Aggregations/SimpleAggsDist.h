#pragma once

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace calcs
{
template <typename T>
T AllocateAndAggregateDist( std::vector<T> container )
{
    std::string funcName = "AllocateAndAggregate" + std::string( typeid( T ).name() );

    // distribute data before sending it on nodes
    // consider adding Distribution class taking std::vector<T> container and
    // choping it on fragments according to number of nodes
    // with data distributed using predefined modes like:
    // - hash
    // - roundrobin
    // - etc.

    return 5;
}

} // namespace calcs
