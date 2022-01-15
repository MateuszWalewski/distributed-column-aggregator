#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerHub
{
public:
    explicit SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients );

    // Make it as a variadic template
    template <typename T> std::vector<T> CallRPCMethod( const std::string & methodName, T arg1 );
    template <typename T> std::vector<T> CallRPCMethod( const std::string & methodName, int arg1, T arg2 )
    {
        std::vector<T> results( 0, 0 );

        for ( auto & x : mHub )
        {
            // emplace back?
            results.push_back( x->call( methodName, arg1, arg2 ).template as<T>() );
        }

        return results;
    }

private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
