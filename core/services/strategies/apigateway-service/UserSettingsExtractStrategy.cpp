/**
 * @file UserSettingsExtractStrategy.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/UserSettingsExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"
#include "core/services/messages/apigateway-service/UserSettingsMessage.h"
#include "models/userprofile/UserSettingsModel.h"

UserSettingsExtractStrategy::~UserSettingsExtractStrategy()
{
}

void UserSettingsExtractStrategy::execute(const UserSettingsMessage &message)
{
	extract(message);
}

void UserSettingsExtractStrategy::extract(const UserSettingsMessage &message)
{
	qDebug() << "UserSettingsExtractStrategy::extract";
	auto userSettings = message.getUserSettings();
	auto model = ModelController::getInstance().getUserSettingsModel(); // still in worker thread

	if (auto modelPtr = model.lock()) {
		modelPtr->setUserId(userSettings.userId);
		modelPtr->setTheme(userSettings.theme);
		modelPtr->setLanguage(userSettings.language);
		modelPtr->setPomodoroDuration(userSettings.pomodoroDuration);
		modelPtr->setShortBreakDuration(userSettings.shortBreakDuration);
		modelPtr->setLongBreakDuration(userSettings.longBreakDuration);
		modelPtr->setLongBreakInterval(userSettings.longBreakInterval);
		modelPtr->setAutoStartShortBreak(userSettings.autoStartShortBreak);
		modelPtr->setAutoStartLongBreak(userSettings.autoStartLongBreak);
		modelPtr->setAutoStartPomodoro(userSettings.autoStartPomodoro);
		modelPtr->setShortBreakNotification(userSettings.shortBreakNotification);
		modelPtr->setLongBreakNotification(userSettings.longBreakNotification);
		modelPtr->setPomodoroNotification(userSettings.pomodoroNotification);
		modelPtr->setAutoStartMusic(userSettings.autoStartMusic);
		modelPtr->setAutoStartNextTask(userSettings.autoStartNextTask);
	} else {
		qDebug() << "Failed to lock UserSettingsModel";
	}
}
