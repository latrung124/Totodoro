/**
 * @file UserSettingsMessage.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsMessage class.
 */

#ifndef USER_SETTINGS_MESSAGE_H
#define USER_SETTINGS_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"
#include <ApiGatewayServiceUtils.h>

class UserSettingsMessage : public Message
{
public:
	using UserSettings = apigateway_service::utils::user::Settings;
	using ExtractUserSettingsStrategyUPtr = std::unique_ptr<IStrategy<UserSettingsMessage>>;

	UserSettingsMessage(ExtractUserSettingsStrategyUPtr strategy);
	~UserSettingsMessage();

	void setUserSettings(const UserSettings &settings);
	UserSettings getUserSettings() const;

	void execute() override;

private:
	UserSettings m_userSettings;
	ExtractUserSettingsStrategyUPtr m_strategy;
};

#endif // USER_SETTINGS_MESSAGE_H
