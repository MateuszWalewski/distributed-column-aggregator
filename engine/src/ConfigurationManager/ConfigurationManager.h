#pragma once
#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

using ConfigParameter = std::variant<std::string, uint16_t, size_t>;

class ConfigurationManager {
public:
    ConfigurationManager() = default;
    std::optional<std::string> LoadConnectionInfoOnNode();
    std::optional<std::string> LoadConnectionInfoOnHub();
    void PrintConnectionInfo(const ConfigParameter& value, const std::string& label);
    void setConfigParameter(const std::string& key, ConfigParameter value);
    ConfigParameter getConfigParameter(const std::string& key);

private:
    std::unordered_map<std::string, ConfigParameter> config;
    std::optional<std::string> LoadTcpConnectionInfoOnNode();
    std::optional<std::string> LoadRpcConnectionInfoOnNode();
    std::optional<std::string> LoadTcpConnectionInfoOnHub();
    std::optional<std::string> LoadRpcConnectionInfoOnHub();
};
