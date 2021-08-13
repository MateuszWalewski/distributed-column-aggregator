#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandler
{
public:
    explicit SessionHandler( std::shared_ptr<rpc::server> srv );
    // make it && to enable move semantics
    explicit SessionHandler( std::vector<std::shared_ptr<rpc::client>> clients );

    void RunServer();
    void BindMethods();

    // Make it as a variadic template
    auto CallRPCMethod( const std::string & methodName, int arg1 ) -> std::vector<int>;
    auto CallRPCMethod( const std::string & methodName, int arg1, int arg2 ) -> std::vector<int>;

private:
    // make a vector of shared_ptrs
    std::shared_ptr<rpc::server> mNode;
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
