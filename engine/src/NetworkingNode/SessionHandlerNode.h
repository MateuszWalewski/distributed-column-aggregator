#pragma once
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerNode
{
public:
    explicit SessionHandlerNode( std::shared_ptr<rpc::server> srv );

    void RunServer();
    void BindMethods();

private:
    std::shared_ptr<rpc::server> mNode;
};
