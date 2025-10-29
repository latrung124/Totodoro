/**
 * @file UserSettingsMessage.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsMessage class.
 */

#include "UserSettingsMessage.h"

namespace {
using namespace apigateway_service::utils::user;
}

UserSettingsMessage::UserSettingsMessage(ExtractUserSettingsStrategyUPtr strategy)
    : Message(MessageId::UserSettingsMessage)
    , m_strategy(std::move(strategy))
{
}

UserSettingsMessage::~UserSettingsMessage() = default;

void UserSettingsMessage::setUserSettings(const UserSettings &settings)
{
	m_userSettings = settings;
}

UserSettingsMessage::UserSettings UserSettingsMessage::getUserSettings() const
{
	return m_userSettings;
}

void UserSettingsMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
