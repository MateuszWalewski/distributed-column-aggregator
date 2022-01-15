#include <unistd.h>

#include <iostream>
#include <string>
#include <typeinfo>

#include "Aggregations/SimpleAggsDist.h"
#include "ParameterController/ParameterControllerHub.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    PCTRL().LoadHubConnectionInfo( argv, argc );
    PCTRL().PrintHubConnectionInfo();

    int size = 6;
    int key = 4;

    auto result = calcs::AllocateAndAggregateDist( size, key );

    std::cout << "The result is: " << result << std::endl;
    std::cout << "The result type is: " << typeid( result ).name() << std::endl;

    double sizeD = 6.0;
    double keyD = 4.0;

    auto resultD = calcs::AllocateAndAggregateDist( sizeD, keyD );

    std::cout << "The result with double is: " << resultD << std::endl;
    std::cout << "The result with double type is: " << typeid( resultD ).name() << std::endl;

    return 0;
}
