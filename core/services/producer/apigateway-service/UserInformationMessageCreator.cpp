/**
 * @file UserInformationMessageCreator.cpp
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the implementation of the UserInformationMessageCreator class.
 */

#include "core/services/producer/apigateway-service/UserInformationMessageCreator.h"
#include "core/services/messages/apigateway-service/UserInformationMessage.h"
#include "core/services/strategies/apigateway-service/UserInformationExtractStrategy.h"

ServiceMessageUPtr UserInformationMessageCreator::create(ParamContainerBase *param) const
{
	auto *container =
	    dynamic_cast<core::factories::ParamContainer<UserInformationMessage::UserInformation> *>(
	        param);
	if (container == nullptr) {
		return std::make_unique<UserInformationMessage>(
		    std::make_unique<UserInformationExtractStrategy>());
	}

	auto paramTuple = container->getParams();
	auto userInfo = std::get<0>(paramTuple);

	auto message = std::make_unique<UserInformationMessage>(
	    std::make_unique<UserInformationExtractStrategy>());
	message->setUserInformation(userInfo);
	return message;
}
