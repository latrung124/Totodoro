/**
 * @file UserInformationExtractStrategy.cpp
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the implementation of the UserInformationExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/extract/UserInformationExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"
#include "models/userprofile/UserInformationModel.h"

#include "core/services/messages/apigateway-service/UserInformationMessage.h"

UserInformationExtractStrategy::~UserInformationExtractStrategy()
{
}

void UserInformationExtractStrategy::execute(const UserInformationMessage &message)
{
	extract(message);
}

void UserInformationExtractStrategy::extract(const UserInformationMessage &message)
{
	qDebug() << "UserInformationExtractStrategy::extract";
	auto userInfo = message.getUserInformation();
	auto model = ModelController::getInstance().getUserInformationModel(); // still in worker thread
	if (auto modelPtr = model.lock()) {
		modelPtr->setUserId(userInfo.userId);
		modelPtr->setUsername(userInfo.username);
		modelPtr->setEmail(userInfo.email);
		// TODO: Set other user information as needed
	} else {
		qDebug() << "Failed to lock UserModel";
	}
}
