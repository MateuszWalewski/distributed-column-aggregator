#include "SessionHandlerNode.h"

#include <iostream>
#include <memory>

#include "AggregationsNode/SimpleAggs.h"
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
    mNode->bind( "CreateColumni", &calcs::CreateColumn<int> );
    mNode->bind( "DeleteColumni", &calcs::DeleteColumn<int> );
    mNode->bind( "AddElementi", &calcs::AddElement<int> );
    mNode->bind( "PrintColumni", &calcs::PrintColumn<int> );
    mNode->bind( "LoadCsvDatai", &calcs::LoadCsvData<int> );
    mNode->bind( "Sumi", &calcs::Sum<int> );
}
