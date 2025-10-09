/*
 * File: ConfigManager.h
 * Author: trung.la
 * Date: 03-27-2025
 * Description: This file contains the declarations for the ConfigManager class, which manages
 * configuration settings for the gateway.
 */

#ifndef COMMON_CONFIGMANAGER_H_
#define COMMON_CONFIGMANAGER_H_

#include <string>
#include <string_view>
#include <unordered_map>

namespace gateway::common {

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

} // namespace gateway::common

#endif // COMMON_CONFIGMANAGER_H_
