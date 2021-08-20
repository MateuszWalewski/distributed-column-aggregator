#include "SessionHandlerNode.h"

#include <iostream>
#include <memory>

#include "Aggregations/SimpleAggs.h"
#include "rpc/client.h"
#include "rpc/server.h"

SessionHandlerNode::SessionHandlerNode( std::shared_ptr<rpc::server> srv ) : mNode( move( srv ) )
{
    std::cout << "SessionHandlerNode ctor on the server side called ! " << std::endl;
}

void SessionHandlerNode::RunServer()
{
    mNode->run();
}

void SessionHandlerNode::BindMethods()
{
    // TODO: move all binds to the separate class
    mNode->bind( "AllocateAndAggregate", &calcs::AllocateAndAggregate );
}

