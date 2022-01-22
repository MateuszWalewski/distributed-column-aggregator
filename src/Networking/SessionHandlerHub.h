#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerHub
{
public:
    explicit SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients );

    template <typename T> std::vector<T> CallRPCMethod( const std::string & methodName, std::vector<T> arg1 )
    {
        // TODO: make the funtion making calls in parallel on many nodes
        // try async_call()

        std::vector<T> results( 0, 0.0 );

        for ( auto & x : mHub )
        {
            // emplace back?
            results.push_back( x->call( methodName, arg1 ).template as<T>() );
        }

        return results;
    }

private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
