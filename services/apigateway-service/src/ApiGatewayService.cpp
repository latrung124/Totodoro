/**
 * @file ApiGatewayService.cpp
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the implementation of the ApiGatewayService class.
 */

#include "ApiGatewayService.h"
#include "IApiGatewayServiceListener.h"

#include "Gateway.h"

#include "common/Properties.h"
#include "common/UserProperties.h"
#include "manager/UserApiGatewayManager.h"

namespace {
using Information = apigateway_service::utils::user::Information;
using Settings = apigateway_service::utils::user::Settings;
} // namespace

ApiGatewayService::ApiGatewayService()
    : m_gateway(std::make_unique<gateway::Gateway>())
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
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserProperties userProps;
	userProps.userId = userInformation.userId;
	userProps.email = userInformation.email;
	userProps.userName = userInformation.username;
	userProps.createdTime = userInformation.createdTime;
	userProps.lastUpdatedTime = userInformation.lastUpdatedTime;
	properties.property = userProps;
	managerPtr->trigger(gateway::RequestType::CreateUser, properties);
}

void ApiGatewayService::requestGetUserInformation(const std::string &userId)
{
	if (!m_gateway) {
		return;
	}

	auto managerWeakPtr = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	auto managerPtr = managerWeakPtr.lock();
	if (!managerPtr) {
		return;
	}

	gateway::Properties properties;
	gateway::UserProperties userProps;
	userProps.userId = userId;
	properties.property = userProps;
	managerPtr->trigger(gateway::RequestType::GetUserProperties, properties);
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

void ApiGatewayService::onResponseCreateUser(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseGetUserInformation(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseGetUserSettings(const Settings &settings)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserSettingsChanged(settings);
		}
	}
}

void ApiGatewayService::onResponseUpdateUserInformation(const Information &userInformation)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserInformationChanged(userInformation);
		}
	}
}

void ApiGatewayService::onResponseUpdateUserSettings(const Settings &settings)
{
	for (const auto &listener : m_listeners) {
		auto apiListener = dynamic_cast<IApiGatewayServiceListener *>(listener);
		if (apiListener) {
			apiListener->onUserSettingsChanged(settings);
		}
	}
}
