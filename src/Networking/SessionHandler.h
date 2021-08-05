#include "rpc/server.h"
#include "rpc/client.h"
#include <memory>

class SessionHandler
{
    public:
    SessionHandler(std::shared_ptr<rpc::server> srv);

    SessionHandler(std::shared_ptr<rpc::client> client);

    void RunServer();
    void BindMethods();

    // Make it as a variadic template
    int CallRPCMethod(std::string methodName, int arg1);
    int CallRPCMethod(std::string methodName, int arg1, int arg2);

    private:
    // make a vector of shared_ptrs
    std::shared_ptr<rpc::server> mNodes; 
    std::shared_ptr<rpc::client> mHub;

};
