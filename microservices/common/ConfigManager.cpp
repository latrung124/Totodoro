/*
* File: ConfigManager.cpp
* Author: trung.la
* Date: 03-27-2025
* Description: This file contains the definitions for the ConfigManager class, which manages configuration settings for the microservices.
*/

#include "microservices/common/ConfigManager.h"

#include <yaml-cpp/yaml.h>

microservices::common::ConfigManager::ConfigManager(std::string_view configFilePath)
{
    using namespace microservices::common;
    // Load configuration from yaml file
    YAML::Node config = YAML::LoadFile(std::string(configPath));
    m_env = config["environment"].as<std::string>();

    for (const auto &service : config["services"]) {
        m_services[service.first.as<std::string>()] =
        m_env == "cloud" ? service.second["cloud"].as<std::string>() : service.second["local"].as<std::string>();
    }
}

std::string microservices::common::ConfigManager::getServiceUrl(const std::string &serviceName) const
{
    // Get service URL from configuration
    // ...
    auto it = m_services.find(serviceName);
    if (it != m_services.end())
    {
        return it->second;
    } else {
        return "";
    }
}
