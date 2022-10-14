#include "SessionHandlerHub.h"

#include <iostream>
#include <memory>

#include "rpc/client.h"
#include "rpc/server.h"

SessionHandlerHub::SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients ) : mHub( move( clients ) )
{
    std::cout << "SessionHandlerHub ctor on the client side called ! " << std::endl;
}
