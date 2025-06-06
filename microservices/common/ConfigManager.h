/*
* File: ConfigManager.h
* Author: trung.la
* Date: 03-27-2025
* Description: This file contains the declarations for the ConfigManager class, which manages configuration settings for the microservices.
*/

#ifndef COMMON_CONFIGMANAGER_H_
#define COMMON_CONFIGMANAGER_H_

#include <string_view>
#include <string>
#include <unordered_map>

namespace microservices::common {

class ConfigManager
{
public:
    ConfigManager(std::string_view configPath);
    ~ConfigManager() = default;

    std::string getServiceUrl(const std::string &serviceName) const;

private:
    std::string m_env;
    std::unordered_map<std::string, std::string> m_services;
};

} // namespace microservices::common

#endif // COMMON_CONFIGMANAGER_H_