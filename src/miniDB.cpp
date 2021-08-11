#include <unistd.h>

#include <iostream>
#include <string>

#include "Aggregations/SimpleAggsDist.h"
#include "ParameterController/ParameterController.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    PCTRL().LoadParameter( std::string( argv[1] ) );
    PCTRL().LoadHubConnectionInfo( argv, argc );
    PCTRL().PrintHubConnectionInfo();

    int size = 6;
    int key = 4;

    auto result = calcs::AllocateAndAggregateDist( size, key );

    std::cout << "The result is: " << result << std::endl;
    return 0;
}
