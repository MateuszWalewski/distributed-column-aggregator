#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>

class SessionHandler
{
    public:
    SessionHandler(std::shared_ptr<rpc::server> srv): mNodes(srv)
    {};

    SessionHandler(std::shared_ptr<rpc::client> client): mHub(client)
    {};

    std::shared_ptr<rpc::server> GetNode() const
    {
        return mNodes;
    }

    std::shared_ptr<rpc::client> GetHub() const
    {
        return mHub;
    }

    private:
    // make a vector of shared_ptrs
    std::shared_ptr<rpc::server> mNodes; 
    std::shared_ptr<rpc::client> mHub;

};
