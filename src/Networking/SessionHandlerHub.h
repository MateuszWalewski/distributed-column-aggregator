#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerHub
{
public:
    explicit SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients );

    // Make it as a variadic template
    template <typename T> auto CallRPCMethod( const std::string & methodName, T arg1 ) -> std::vector<T>;
    template <typename T> auto CallRPCMethod( const std::string & methodName, T arg1, T arg2 ) -> std::vector<T>;

private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
