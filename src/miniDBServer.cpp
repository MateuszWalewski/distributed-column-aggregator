#include "Context/GlobalContext.h"
#include "ParameterController/ParameterController.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    PCTRL().LoadParameter( std::string( argv[1] ) );
    PCTRL().LoadNodeConnectionInfo( argv );
    PCTRL().PrintNodeConnectionInfo();

    CTX().GetSessionHandler().BindMethods();
    CTX().GetSessionHandler().RunServer();

    return 0;
}
