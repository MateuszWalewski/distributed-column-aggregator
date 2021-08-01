#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>
#include "SessionHandler.h"

  SessionHandler::SessionHandler(std::shared_ptr<rpc::server> srv): mNodes(srv)
  {};

  SessionHandler::SessionHandler(std::shared_ptr<rpc::client> client): mHub(client)
  {};

  std::shared_ptr<rpc::server> SessionHandler::GetNode() const
  {
      return mNodes;
  }

  std::shared_ptr<rpc::client> SessionHandler::GetHub() const
  {
      return mHub;
  }


