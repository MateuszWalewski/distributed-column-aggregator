#pragma once
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

using ConfigParameter = std::variant<std::string, uint, size_t>;

class ConfigurationManager {
public:
    ConfigurationManager() = default;
    void LoadConnectionInfo(const std::vector<std::string>& tcpConnectionInfo);
    void PrintConnectionInfo(const ConfigParameter& value, const std::string& label);
    void setConfigParameter(const std::string& key, ConfigParameter value);
    ConfigParameter getConfigParameter(const std::string& key);

private:
    std::unordered_map<std::string, ConfigParameter> config;
};
