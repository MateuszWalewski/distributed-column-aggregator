#include "Context/GlobalContext.h"
#include "ParameterController/ParameterController.h"
#include "Aggregations/SimpleAggs.h"

int main(int argc, char * argv[]) {

    PCTRL().LoadParameter(std::string(argv[1]));
    // TODO: move all binds to the separate class
    CTX().GetSessionHandler().GetNode()->bind("AllocateAndAggregate", &calcs::AllocateAndAggregate);
    CTX().GetSessionHandler().GetNode()->run();

    return 0;
}
