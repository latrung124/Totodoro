/**
 * @file UserSettingsMessageCreator.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsMessageCreator class.
 */

#include "core/services/producer/apigateway-service/UserSettingsMessageCreator.h"
#include "core/services/messages/apigateway-service/UserSettingsMessage.h"
#include "core/services/strategies/apigateway-service/extract/UserSettingsExtractStrategy.h"

ServiceMessageUPtr UserSettingsMessageCreator::create(ParamContainerBase *param) const
{
	auto *container =
	    dynamic_cast<core::factories::ParamContainer<UserSettingsMessage::UserSettings> *>(param);
	if (container == nullptr) {
		return std::make_unique<UserSettingsMessage>(
		    std::make_unique<UserSettingsExtractStrategy>());
	}

	const auto &userSettings = container->getParam();

	auto message = std::make_unique<UserSettingsMessage>(
	    std::make_unique<UserSettingsExtractStrategy>());
	message->setUserSettings(userSettings);
	return message;
}
