#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>
#include "SessionHandler.h"
#include <iostream>

  SessionHandler::SessionHandler(std::shared_ptr<rpc::server> srv): mNodes(srv)
  {
    std::cout << "SessionHandler ctor on the server side called ! " << std::endl;
  
  };

  SessionHandler::SessionHandler(std::shared_ptr<rpc::client> client): mHub(client)
  {
    std::cout << "SessionHandler ctor on the client side called ! " << std::endl;
  };


  std::shared_ptr<rpc::server> SessionHandler::GetNode() const
  {
      return mNodes;
  }

  std::shared_ptr<rpc::client> SessionHandler::GetHub() const
  {
      return mHub;
  }


