#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>

class SessionHandler
{
    public:
    SessionHandler(std::shared_ptr<rpc::server> srv);

    SessionHandler(std::shared_ptr<rpc::client> client);

    std::shared_ptr<rpc::server> GetNode() const;

    std::shared_ptr<rpc::client> GetHub() const;

    private:
    // make a vector of shared_ptrs
    std::shared_ptr<rpc::server> mNodes; 
    std::shared_ptr<rpc::client> mHub;

};
