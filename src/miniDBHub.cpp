#include <unistd.h>

#include <fstream>
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

    std::vector<double> containerI;

    LoadCsvToDataColumn( "/home/mwal/distributedDBPrototype/src/data1.csv", containerI );

    PrintVector( containerI, "containerI on Hub" );

    auto result = calcs::AllocateAndAggregateDist( containerI );

    std::cout << "Result on hub: " << result << std::endl;

    return 0;
}
