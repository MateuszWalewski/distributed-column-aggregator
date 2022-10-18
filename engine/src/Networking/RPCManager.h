#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

class RPCManager
{
public:
    template <typename T, typename... Args> 
    std::vector<T> CallRPCMethod( const std::string & methodName, Args... args )
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

    template <typename... Args> 
    void CallRPCMethod( const std::string & methodName, Args... args )
    {
        for ( auto & x : mHub )
        {
            // Type promotion is not included here. May cause conversion problems while aggregatting floatig points
            // Promoted types should be included
            x->call( methodName, args... );
        }
    }


    void RunServer();
    void BindMethods();

    void SetRPCClients(std::vector<std::shared_ptr<rpc::client>> clients);
    void SetRPCServer(std::shared_ptr<rpc::server> srv);

    std::shared_ptr<rpc::server> GetRPCServer();


private:
    std::vector<std::shared_ptr<rpc::client>> mHub;
    std::shared_ptr<rpc::server> mNode;
};
