#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerHub
{
public:
    explicit SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients );

    // Make it as a variadic template
    auto CallRPCMethod( const std::string & methodName, int arg1 ) -> std::vector<int>;
    auto CallRPCMethod( const std::string & methodName, int arg1, int arg2 ) -> std::vector<int>;

private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
