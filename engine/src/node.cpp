#include "ContextNode/GlobalContextNode.h"
#include "ParameterControllerNode/ParameterControllerNode.h"

int main( int argc, char * argv[] )
{
    // TODO: input sanity check!!!
    (void) argc; // to silent warning
    PCTRL().LoadNodeConnectionInfo( argv );
    PCTRL().PrintNodeConnectionInfo();

    CTX().GetSessionHandler().BindMethods();
    CTX().GetSessionHandler().RunServer();

    return 0;
}
