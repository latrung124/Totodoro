/**
 * @file ApiGatewayService.cpp
 * @author trung.la
 * @date 09-20-2025
 * @brief This file contains the implementation of the ApiGatewayService class.
 */

#include "ApiGatewayService.h"
#include "IApiGatewayServiceListener.h"

#include "common/ApiUtilities.h"
#include "common/CommonDefine.h"
#include "common/UserProperties.h"
#include "Gateway.h"
#include "manager/UserApiGatewayManager.h"

namespace {

using Information = apigateway_service::utils::user::Information;
using Settings = apigateway_service::utils::user::Settings;

using namespace gateway;

} // namespace

ApiGatewayService::ApiGatewayService()
    : m_gateway(std::make_unique<Gateway>())
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
	if (!m_gateway) {
		return;
	}

	m_gateway->start();
}

void ApiGatewayService::stop()
{
	if (!m_gateway) {
		return;
	}

	m_gateway->stop();
}

void ApiGatewayService::requestCreateUser(const Information &userInformation)
{
	const auto userApiManagerWeak = m_gateway->getApiGatewayManager(gateway::RouteType::User);
	if (userApiManagerWeak.expired()) {
		return;
	}
	const auto userApiManager = userApiManagerWeak.lock();
	if (!userApiManager) {
		return;
	}

	const gateway::UserProperties userProperties{
	    .userId = userInformation.userId,
	    .email = userInformation.email,
	    .userName = userInformation.username,
	    .createdTime = userInformation.createdTime,
	    .lastUpdatedTime = userInformation.lastUpdatedTime,
	};

	userApiManager->request(gateway::ApiRequest{
	    .requestType = gateway::RequestType::CreateUser,
	    .data = userProperties,
	});
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
