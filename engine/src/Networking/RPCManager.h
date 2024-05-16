#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

using RPCClientHandlers = std::vector<std::shared_ptr<rpc::client>>;
using DataLoadRanges = std::vector<std::pair<size_t, size_t>>;
using RPCHandle = std::future<clmdep_msgpack::v1::object_handle>;
class RPCManager
{
public:
    RPCManager() = default;
    template <typename T, typename... Args>
    std::vector<T> CallRPCMethod( const std::string& methodName, Args... args )
    {
        std::vector<RPCHandle> handles;
        std::vector<T> results;
        for ( auto& rpcClient : mRPCClientHandlers )
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
    std::vector<int> CallRPCMethodSizes( const std::string& methodName, Args... args )
    {
        std::vector<RPCHandle> handles;
        std::vector<int> results;
        for ( auto& rpcClient : mRPCClientHandlers )
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
    void CallRPCMethod( const std::string& methodName, Args... args )
    {
        std::vector<RPCHandle> handles;
        for ( auto& rpcClient : mRPCClientHandlers )
        {
            handles.push_back( rpcClient->async_call( methodName, args... ) );
        }

        for ( auto& handle : handles )
        {
            handle.get();
        }
    }

    template <typename... Args>
    void CallRPCMethod( const std::string& methodName, DataLoadRanges ranges, Args... args )
    {
        std::vector<RPCHandle> handles;
        for ( size_t i = 0; i < mRPCClientHandlers.size(); i++ )
        {
            if ( i >= ranges.size() )
                break;

            size_t begin = ranges[i].first;
            size_t end = ranges[i].second;

            handles.push_back( mRPCClientHandlers[i]->async_call( methodName, begin, end, args... ) );
        }

        for ( auto& handle : handles )
        {
            handle.get();
        }
    }

    template <typename... Args>
    void CallRPCMethodOnTheGivenNode( const std::string& methodName, const size_t nodeNumber, Args... args )
    {
        if ( nodeNumber <= 0 )
        {
            std::cout << "Error: Incorrect number of node: " + std::to_string( nodeNumber ) << '\n';
            return;
        }

        if ( nodeNumber > mRPCClientHandlers.size() )
        {
            std::cout << "Error: there is no " + std::to_string( nodeNumber ) + " nodes configured." << '\n';
            std::cout << "The number of available nodes is " + std::to_string( mRPCClientHandlers.size() ) << '\n';
            return;
        }
        size_t nodeIdx = nodeNumber - 1;
        mRPCClientHandlers[nodeIdx]->call( methodName, args... );
    }

    void RunServer();

    std::shared_ptr<rpc::server> GetRPCServer();
    void SetRPCClientInfo( RPCClientHandlers rpcClientHandlers );
    void SetRPCServerInfo( std::shared_ptr<rpc::server> rpcServerHandler );

private:
    RPCClientHandlers mRPCClientHandlers;
    std::shared_ptr<rpc::server> mRPCServerHandler;
};
