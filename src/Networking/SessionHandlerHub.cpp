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
template <typename T> auto SessionHandlerHub::CallRPCMethod( const std::string & methodName, T arg1 ) -> std::vector<T>
{
    std::vector<T> results( 0, 0 );

    for ( auto & x : mHub )
    {
        // emplace back?
        results.push_back( x->call( methodName, arg1 ).template as<T>() );
    }

    return results;
}
// TODOS:
// must be templated!!!
// forloop change to runlambda by threads
//  check if it is generic enough
template <typename T> auto SessionHandlerHub::CallRPCMethod( const std::string & methodName, T arg1, T arg2 ) -> std::vector<T>
{
    std::vector<T> results( 0, 0 );

    for ( auto & x : mHub )
    {
        // emplace back?
        results.push_back( x->call( methodName, arg1, arg2 ).template as<T>() );
    }

    return results;
}
