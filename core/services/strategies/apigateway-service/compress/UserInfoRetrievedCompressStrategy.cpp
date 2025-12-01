/**
 * @file UserInfoRetrievedCompressStrategy.cpp
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the implementation of the UserInfoRetrievedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/UserInfoRetrievedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestUserInformationAsyncMessage.h"
#include "core/services/ServiceManager.h"

UserInfoRetrievedCompressStrategy::~UserInfoRetrievedCompressStrategy() = default;

void UserInfoRetrievedCompressStrategy::execute(const RequestUserInformationAsyncMessage &message)
{
	compress(message);
}

void UserInfoRetrievedCompressStrategy::compress(const RequestUserInformationAsyncMessage &message)
{
	qDebug() << "UserInfoRetrievedCompressStrategy::compress, retrieving user info for email:"
	         << QString::fromStdString(message.getEmail());
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestGetUserInformation(message.getEmail());
	} else {
		qDebug() << "UserInfoRetrievedCompressStrategy::compress - Service not found";
	}
}
