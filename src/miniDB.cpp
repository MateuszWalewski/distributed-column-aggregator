#include <unistd.h>

#include <iostream>
#include <string>

#include "Aggregations/SimpleAggsDist.h"
#include "ParameterController/ParameterController.h"

int main( int argc, char * argv[] )
{
    PCTRL().LoadParameter( std::string( argv[1] ) );

    int size = 6;
    int key = 4;

    usleep( 10000000 );

    auto result = calcs::AllocateAndAggregateDist( size, key );

    std::cout << "The result is: " << result << std::endl;
    return 0;
}
