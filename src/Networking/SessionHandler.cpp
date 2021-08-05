#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>
#include "SessionHandler.h"
#include <iostream>
#include "../Aggregations/SimpleAggs.h"

// TODO: Make it as one ctr
SessionHandler::SessionHandler(std::shared_ptr<rpc::server> srv): mNodes(srv)
{
  std::cout << "SessionHandler ctor on the server side called ! " << std::endl;

};

SessionHandler::SessionHandler(std::shared_ptr<rpc::client> client): mHub(client)
{
  std::cout << "SessionHandler ctor on the client side called ! " << std::endl;
};


void SessionHandler::RunServer()
{
    mNodes->run();
}

void SessionHandler::BindMethods()
{
    // TODO: move all binds to the separate class
    mNodes->bind("AllocateAndAggregate", &calcs::AllocateAndAggregate);


}

// must be templated!!!
int SessionHandler::CallRPCMethod(std::string methodName, int arg1)
{
    return mHub->call(methodName, arg1).as<int>();

}

// must be templated!!!
int SessionHandler::CallRPCMethod(std::string methodName, int arg1, int arg2)
{
   return mHub->call(methodName, arg1, arg2).as<int>();

}


