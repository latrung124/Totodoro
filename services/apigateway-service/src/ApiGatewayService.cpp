/**
 * @file ApiGatewayService.cpp
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the implementation of the ApiGatewayService class.
 */

#include "ApiGatewayService.h"

namespace {
using Information = apigateway_service::utils::user::Information;
using Settings = apigateway_service::utils::user::Settings;
} // namespace

ApiGatewayService::ApiGatewayService()
{
}

ApiGatewayService::~ApiGatewayService()
{
}

void ApiGatewayService::registerListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (const auto &l : m_listeners) {
		if (l == listener) {
			return;
		}
	}

	m_listeners.push_back(const_cast<IServiceListener *>(listener));
}

void ApiGatewayService::unregisterListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it) {
		if (*it == listener) {
			m_listeners.erase(it);
			return;
		}
	}
}

void ApiGatewayService::start()
{
	// Initialize resources, connections, etc.
}

void ApiGatewayService::stop()
{
	// Clean up resources, connections, etc.
}

void ApiGatewayService::requestCreateUser(const Information &userInformation)
{
	// Simulate user creation (replace with actual implementation)
}

void ApiGatewayService::requestGetUserInformation(const std::string &userId)
{
	// Simulate fetching user information (replace with actual implementation)
}

void ApiGatewayService::requestGetUserSettings(const std::string &userId)
{
	// Simulate fetching user settings (replace with actual implementation)
}

void ApiGatewayService::requestUpdateUserInformation(const Information &info)
{
	// Simulate updating user information (replace with actual implementation)
}

void ApiGatewayService::requestUpdateUserSettings(const Settings &settings)
{
	// Simulate updating user settings (replace with actual implementation)
}
