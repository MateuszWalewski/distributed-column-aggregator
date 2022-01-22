#pragma once

#include "Context/GlobalContextHub.h"
#include "SimpleAggs.h"
#include "Tools/Utility.h"
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace calcs
{
template <typename T> T AllocateAndAggregateDist( std::vector<T> container )
{
    std::string funcName = "AllocateAndAggregate" + std::string( typeid( T ).name() );

    auto vectors = PartitionDataToSendOnNodes( container, PCTRL().GetNumberOfNodes() );

    // distribute data before sending it on nodes
    // consider adding Distribution class taking std::vector<T> container and
    // choping it on fragments according to number of nodes
    // with data distributed using predefined modes like:
    // - hash
    // - roundrobin
    // - etc.

    auto results = CTX().GetSessionHandler().CallRPCMethod( funcName, vectors );
    int nodeNo = 1;
    for ( auto & x : results )
    {
        std::cout << "result from node" + std::to_string( nodeNo ) << " " << x << std::endl;
        nodeNo++;
    }

    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
}
} // namespace calcs
