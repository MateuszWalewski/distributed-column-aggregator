#include "ConfigurationManager.h"
#include "constants.h"
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <Tools/Utility.h>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <rpc/client.h>

std::optional<std::string> ConfigurationManager::LoadConnectionInfoOnHub() {
    if (!this->LoadTcpConnectionInfoOnHub()) {
        return std::nullopt;
    }
    if (!this->LoadRpcConnectionInfoOnHub()) {
        return std::nullopt;
    }
    return "ok";
}

std::optional<std::string> ConfigurationManager::LoadConnectionInfoOnNode() {
    if (!this->LoadRpcConnectionInfoOnNode()) {
        return std::nullopt;
    }
    if (!this->LoadTcpConnectionInfoOnNode()) {
        return std::nullopt;
    }
    return "ok";
}

void ConfigurationManager::setConfigParameter(const std::string& key, ConfigParameter value) {
    config[key] = std::move(value);
}

ConfigParameter ConfigurationManager::getConfigParameter(const std::string& key) {
    return config.at(key);
}

void ConfigurationManager::PrintConnectionInfo(const ConfigParameter& value, const std::string& label) {
    std::cout << label << ": ";
    std::visit([](const auto& val) { std::cout << val << std::endl; }, value);
}

//---------------------- PRIVATE FUNCTIONS -------------------------------------

std::optional<std::string> ConfigurationManager::LoadTcpConnectionInfoOnHub() {
    auto tcpConnectionInfo = util::SplitStringToVector(std::getenv("TCP_PORTS"));
    for (size_t i = 0; i < tcpConnectionInfo.size(); i++) {
        auto tcpPort = util::convertToTcpPortCompliantType(tcpConnectionInfo[i]);
        if (tcpPort) {
            std::string key = TCP_SERVER_PORT + std::to_string(i);
            this->setConfigParameter(key, tcpPort.value());
            this->PrintConnectionInfo(this->getConfigParameter(key), TCP_SERVER_PORT + std::to_string(i));
        } else {
            return std::nullopt;
        }
    }
    return "ok";
}

std::optional<std::string> ConfigurationManager::LoadRpcConnectionInfoOnHub() {
    RpcClientHandlers rpcClientHandlers;
    auto rpcConnectionInfo = util::SplitStringToVector(std::getenv("RPC_CONNECTIONS"));
    for (const auto& info : rpcConnectionInfo) {
        auto rpcInfo = util::getTcpIpInfo(info);
        if (rpcInfo) {
            auto [rpcAddress, rpcPort] = rpcInfo.value();
            auto rpcValidAddress = util::complyWithIpV4(rpcAddress);
            if (!rpcValidAddress) {
                return std::nullopt;
            }
            auto rpcValidPort = util::convertToTcpPortCompliantType(rpcPort);
            if (!rpcValidPort) {
                return std::nullopt;
            }

            rpcClientHandlers.push_back(std::make_unique<rpc::client>(rpcValidAddress.value(), rpcValidPort.value()));
        } else {
            return std::nullopt;
        }
    }

    this->setConfigParameter(NUMBER_OF_NODES, rpcConnectionInfo.size());
    this->PrintConnectionInfo(this->getConfigParameter(NUMBER_OF_NODES), NUMBER_OF_NODES);

    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    rpcInstance.SetRpcClientInfo(move(rpcClientHandlers));
    return "ok";
}

std::optional<std::string> ConfigurationManager::LoadTcpConnectionInfoOnNode() {
    auto tcpInfo = util::getTcpIpInfo(std::getenv("TCP_CONNECTION"));
    if (tcpInfo) {
        auto [tcpAddress, tcpPort] = tcpInfo.value();
        auto tcpValidAddress = util::complyWithIpV4(tcpAddress);
        if (tcpValidAddress) {
            this->setConfigParameter(TCP_SERVER_IP, tcpValidAddress.value());
            this->PrintConnectionInfo(this->getConfigParameter(TCP_SERVER_IP), TCP_SERVER_IP);
        } else {
            return std::nullopt;
        }
        auto tcpValidPort = util::convertToTcpPortCompliantType(tcpPort);
        if (tcpValidPort) {
            this->setConfigParameter(TCP_SERVER_PORT, tcpValidPort.value());
            this->PrintConnectionInfo(this->getConfigParameter(TCP_SERVER_PORT), TCP_SERVER_PORT);
        } else {
            return std::nullopt;
        }
    } else {
        return std::nullopt;
    }

    return "ok";
}

std::optional<std::string> ConfigurationManager::LoadRpcConnectionInfoOnNode() {
    auto rpcPort = util::convertToTcpPortCompliantType(std::getenv("RPC_PORT"));
    if (rpcPort) {
        this->setConfigParameter(RPC_SERVER_PORT, rpcPort.value());
        this->PrintConnectionInfo(this->getConfigParameter(RPC_SERVER_PORT), RPC_SERVER_PORT);
    } else {
        return std::nullopt;
    }

    return "ok";
}
