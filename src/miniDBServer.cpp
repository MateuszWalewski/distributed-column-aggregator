#include "Context/GlobalContext.h"
#include "ParameterController/ParameterController.h"

int main(int argc, char * argv[]) {

    PCTRL().LoadParameter(std::string(argv[1]));
    CTX().GetSessionHandler().BindMethods();
    CTX().GetSessionHandler().RunServer();

    return 0;
}
