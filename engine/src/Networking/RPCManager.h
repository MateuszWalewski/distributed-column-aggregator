#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "rpc/client.h"
#include "rpc/server.h"

using RpcClientHandlers = std::vector<std::unique_ptr<rpc::client>>;
using DataLoadRanges = std::vector<std::pair<size_t, size_t>>;
using RpcHandle = std::future<clmdep_msgpack::v1::object_handle>;

class RPCManager {
public:
    template <typename T>
    std::vector<T> CallRpcMethod(const std::string& methodName, const std::string& columnId) {
        std::vector<RpcHandle> handles;
        for (auto& rpcClient : _rpcClientHandlers) {
            handles.push_back(rpcClient->async_call(methodName, columnId));
        }

        std::vector<T> results;
        for (auto& handle : handles) {
            results.push_back(handle.get().template as<T>());
        }

        return results;
    }

    auto CallRpcMethodVoid(const std::string& methodName, const std::string& columnId) {
        std::vector<RpcHandle> handles;
        for (auto& rpcClient : _rpcClientHandlers) {
            handles.push_back(rpcClient->async_call(methodName, columnId));
        }

        return handles;
    }

    void CompleteRpcTasks(std::vector<RpcHandle>& handles) {
        for (auto& handle : handles) {
            handle.get();
        }
    }

    void CallRpcMethod(const std::string& methodName, const DataLoadRanges& ranges, const std::string& dataFilePath,
                       const std::string& columnId) {
        std::vector<RpcHandle> handles;
        for (size_t i = 0; i < _rpcClientHandlers.size(); i++) {
            if (i >= ranges.size())
                break;

            size_t begin = ranges[i].first;
            size_t end = ranges[i].second;

            handles.push_back(_rpcClientHandlers[i]->async_call(methodName, begin, end, dataFilePath, columnId));
        }

        for (auto& handle : handles) {
            handle.get();
        }
    }
    template <typename T>
    void CallRpcMethodOnTheGivenNode(const std::string& methodName, const size_t nodeNumber, const std::string& columnId,
                                     const T element) {
        if (nodeNumber <= 0) {
            std::cout << "Error: Incorrect number of node: " + std::to_string(nodeNumber) << std::endl;
            return;
        }

        if (nodeNumber > _rpcClientHandlers.size()) {
            std::cout << "Error: there is no " + std::to_string(nodeNumber) + " nodes configured." << std::endl;
            std::cout << "The number of available nodes is " + std::to_string(_rpcClientHandlers.size()) << std::endl;
            return;
        }

        size_t nodeIdx = nodeNumber - 1;
        _rpcClientHandlers[nodeIdx]->call(methodName, columnId, element);
    }

    void RunServer();

    rpc::server* GetRpcServer() const;
    void SetRpcClientInfo(RpcClientHandlers&& rpcClientHandlers);
    void SetRpcServerInfo(std::unique_ptr<rpc::server>&& rpcServerHandler);

private:
    RpcClientHandlers _rpcClientHandlers;
    std::unique_ptr<rpc::server> _rpcServerHandler;
};
