#include "ConfigurationManager.h"
#include "constants.h"
#include <Tools/Utility.h>
#include <boost/lexical_cast.hpp>
#include <iostream>

void ConfigurationManager::LoadConnectionInfo(const std::vector<std::string>& tcpConnectionInfo) {
    for (size_t i = 0; i < tcpConnectionInfo.size(); i++) {
        uint tcpPortNumber;
        try {
            tcpPortNumber = boost::lexical_cast<uint>(tcpConnectionInfo[i]);
        } catch (const boost::bad_lexical_cast& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::string key = TCP_SERVER_PORT + std::to_string(i);
        this->setConfigParameter(key, tcpPortNumber);
    }
}

void ConfigurationManager::setConfigParameter(const std::string& key, ConfigParameter value) {
    config[key] = std::move(value);
}

ConfigParameter ConfigurationManager::getConfigParameter(const std::string& key) {
    return config.at(key);
}

void ConfigurationManager::PrintConnectionInfo(const ConfigParameter& value, const std::string& label) {
    std::cout << "Config parameter " << label << ": ";
    std::visit([](const auto& val) { std::cout << val << std::endl; }, value);
}
