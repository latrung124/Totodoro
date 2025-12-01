/**
 * @file UserSettingsRetrievedCompressStrategy.cpp
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the implementation of the UserSettingsRetrievedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/UserSettingsRetrievedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestUserSettingsAsyncMessage.h"
#include "core/services/ServiceManager.h"

UserSettingsRetrievedCompressStrategy::~UserSettingsRetrievedCompressStrategy() = default;

void UserSettingsRetrievedCompressStrategy::execute(const RequestUserSettingsAsyncMessage &message)
{
	compress(message);
}

void UserSettingsRetrievedCompressStrategy::compress(const RequestUserSettingsAsyncMessage &message)
{
	qDebug()
	    << "UserSettingsRetrievedCompressStrategy::compress, retrieving user settings for user ID:"
	    << QString::fromStdString(message.getUserId());
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestGetUserSettings(message.getUserId());
	} else {
		qDebug() << "UserSettingsRetrievedCompressStrategy::compress - Service not found";
	}
}
