#include "SessionHandler.h"

#include <iostream>
#include <memory>

#include "Aggregations/SimpleAggs.h"
#include "rpc/client.h"
#include "rpc/server.h"

// TODO: Make it as one ctr
SessionHandler::SessionHandler( std::shared_ptr<rpc::server> srv ) : mNode( srv )
{
    std::cout << "SessionHandler ctor on the server side called ! " << std::endl;
};

// Look out on the parameter form! Is it clean? Move semantics?
SessionHandler::SessionHandler( std::vector<std::shared_ptr<rpc::client>> clients ) : mHub( clients )
{
    std::cout << "SessionHandler ctor on the client side called ! " << std::endl;
};

void SessionHandler::RunServer()
{
    mNode->run();
}

void SessionHandler::BindMethods()
{
    // TODO: move all binds to the separate class
    mNode->bind( "AllocateAndAggregate", &calcs::AllocateAndAggregate );
}

// TODOS:
// must be templated!!!
// forloop change to runlambda by threads
//  check if it is generic enough
std::vector<int> SessionHandler::CallRPCMethod( std::string methodName, int arg1 )
{
    std::vector<int> results;

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
std::vector<int> SessionHandler::CallRPCMethod( std::string methodName, int arg1, int arg2 )
{
    std::vector<int> results;

    for ( auto & x : mHub )
    {
        // emplace back?
        results.push_back( x->call( methodName, arg1, arg2 ).as<int>() );
    }

    return results;
}
