#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

using RpcClientHandlers = std::vector<std::unique_ptr<rpc::client>>;
using DataLoadRanges = std::vector<std::pair<size_t, size_t>>;
using RpcHandle = std::future<clmdep_msgpack::v1::object_handle>;
class RPCManager
{
public:
    RPCManager() = default;
    template <typename T, typename... Args>
    std::vector<T> CallRpcMethod( const std::string& methodName, Args... args )
    {
        std::vector<RpcHandle> handles;
        std::vector<T> results;
        for ( auto& rpcClient : mRpcClientHandlers )
        {
            handles.push_back( rpcClient->async_call( methodName, args... ) );
        }

        for ( auto& handle : handles )
        {
            results.push_back( handle.get().template as<T>() );
        }

        return results;
    }

    template <typename T, typename... Args>
    std::vector<int> CallRpcMethodSizes( const std::string& methodName, Args... args )
    {
        std::vector<RpcHandle> handles;
        std::vector<int> results;
        for ( auto& rpcClient : mRpcClientHandlers )
        {
            handles.push_back( rpcClient->async_call( methodName, args... ) );
        }

        for ( auto& handle : handles )
        {
            results.push_back( handle.get().template as<T>() );
        }

        return results;
    }

    template <typename... Args>
    void CallRpcMethod( const std::string& methodName, Args... args )
    {
        std::vector<RpcHandle> handles;
        for ( auto& rpcClient : mRpcClientHandlers )
        {
            handles.push_back( rpcClient->async_call( methodName, args... ) );
        }

        for ( auto& handle : handles )
        {
            handle.get();
        }
    }

    template <typename... Args>
    void CallRpcMethod( const std::string& methodName, DataLoadRanges ranges, Args... args )
    {
        std::vector<RpcHandle> handles;
        for ( size_t i = 0; i < mRpcClientHandlers.size(); i++ )
        {
            if ( i >= ranges.size() )
                break;

            size_t begin = ranges[i].first;
            size_t end = ranges[i].second;

            handles.push_back( mRpcClientHandlers[i]->async_call( methodName, begin, end, args... ) );
        }

        for ( auto& handle : handles )
        {
            handle.get();
        }
    }

    template <typename... Args>
    void CallRpcMethodOnTheGivenNode( const std::string& methodName, const size_t nodeNumber, Args... args )
    {
        if ( nodeNumber <= 0 )
        {
            std::cout << "Error: Incorrect number of node: " + std::to_string( nodeNumber ) << std::endl;
            return;
        }

        if ( nodeNumber > mRpcClientHandlers.size() )
        {
            std::cout << "Error: there is no " + std::to_string( nodeNumber ) + " nodes configured." << std::endl;
            std::cout << "The number of available nodes is " + std::to_string( mRpcClientHandlers.size() ) << std::endl;
            return;
        }
        size_t nodeIdx = nodeNumber - 1;
        mRpcClientHandlers[nodeIdx]->call( methodName, args... );
    }

    void RunServer();

    rpc::server* GetRpcServer() const;
    void SetRpcClientInfo( RpcClientHandlers&& rpcClientHandlers );
    void SetRpcServerInfo( std::unique_ptr<rpc::server>&& rpcServerHandler );

private:
    RpcClientHandlers mRpcClientHandlers;
    std::unique_ptr<rpc::server> mRpcServerHandler;
};
