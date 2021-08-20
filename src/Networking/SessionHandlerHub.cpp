#include "SessionHandlerHub.h"

#include <iostream>
#include <memory>

#include "Aggregations/SimpleAggs.h"
#include "rpc/client.h"
#include "rpc/server.h"


SessionHandlerHub::SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients ) : mHub( move( clients ) )
{
    std::cout << "SessionHandlerHub ctor on the client side called ! " << std::endl;
}

// TODOS:
// must be templated!!!
// forloop change to runlambda by threads
//  check if it is generic enough
auto SessionHandlerHub::CallRPCMethod( const std::string & methodName, int arg1 ) -> std::vector<int>
{
    std::vector<int> results( 0, 0 );

    for ( auto & x : mHub )
    {
        // emplace back?
        results.push_back( x->call( methodName, arg1 ).as<int>() );
    }

    return results;
}
// TODOS:
// must be templated!!!
// forloop change to runlambda by threads
//  check if it is generic enough
auto SessionHandlerHub::CallRPCMethod( const std::string & methodName, int arg1, int arg2 ) -> std::vector<int>
{
    std::vector<int> results( 0, 0 );

    for ( auto & x : mHub )
    {
        // emplace back?
        results.push_back( x->call( methodName, arg1, arg2 ).as<int>() );
    }

    return results;
}
