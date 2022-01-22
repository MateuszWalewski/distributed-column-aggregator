#include <unistd.h>

#include <iostream>
#include <string>
#include <typeinfo>
#include <unistd.h>

#include "Aggregations/SimpleAggsDist.h"
#include "ParameterController/ParameterControllerHub.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    PCTRL().LoadHubConnectionInfo( argv, argc );
    PCTRL().PrintHubConnectionInfo();

    std::vector<int> containerI( 6, 4 );
    std::cout << "calling AllocateAndAggregateDist" << std::endl;
    usleep( 2000000 );
    auto result = calcs::AllocateAndAggregateDist( containerI );

    std::cout << "The result is: " << result << std::endl;
    std::cout << "The result type is: " << typeid( result ).name() << std::endl;

    std::vector<double> containerD( 6, 5.6 );

    auto resultD = calcs::AllocateAndAggregateDist( containerD );

    std::cout << "The result with double is: " << resultD << std::endl;
    std::cout << "The result with double type is: " << typeid( resultD ).name() << std::endl;

    return 0;
}
