#include "Aggregations/SimpleAggsDist.h"
#include "ParameterController/ParameterController.h"
#include <string>
#include <iostream>

int main(int argc, char * argv[]) {
   
    PCTRL().LoadParameter(std::string(argv[1]));

    int size = 6;
    int key = 4;
  
    auto result = calcs::AllocateAndAggregateDist(size, key);

    std::cout << "The result is: " << result << std::endl;
    return 0;
}
