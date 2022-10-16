#include <iostream>
#include <memory>
#include <vector>

#pragma once
#include "rpc/client.h"
#include "rpc/server.h"

class SessionHandlerHub
{
public:
    explicit SessionHandlerHub( std::vector<std::shared_ptr<rpc::client>> clients );

    template <typename T, typename... Args> std::vector<T> CallRPCMethod( const std::string & methodName, Args... args )
    {
        std::vector<T> results;
        for ( auto & x : mHub )
        {
            // Type promotion is not included here. May cause conversion problems while aggregatting floatig points
            // Promoted types should be included
            results.push_back( x->call( methodName, args... ).template as<T>() );
        }

        return results;
    }

    template <typename... Args> void CallRPCMethod( const std::string & methodName, Args... args )
    {
        for ( auto & x : mHub )
        {
            // Type promotion is not included here. May cause conversion problems while aggregatting floatig points
            // Promoted types should be included
            x->call( methodName, args... );
        }
    }

    std::vector<std::shared_ptr<rpc::client>> getClient()
    {
        return mHub;
    }

private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
};
