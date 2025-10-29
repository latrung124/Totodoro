/**
 * @file UserSettingsModel.h
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the declaration of the UserSettingsModel class.
 */

#ifndef USERSETTINGSMODEL_H
#define USERSETTINGSMODEL_H

#include "models/DatabaseModel.h"

#include <mutex>
#include <string>

class UserSettingsModel : public DatabaseModel
{
public:
	UserSettingsModel();
	~UserSettingsModel();

	// Getters and setters for user settings
	std::string getUserId() const;
	void setUserId(const std::string &userId);

	std::string getTheme() const;
	void setTheme(const std::string &theme);

	std::string getLanguage() const;
	void setLanguage(const std::string &language);

	uint32_t getPomodoroDuration() const;
	void setPomodoroDuration(uint32_t duration);

	uint32_t getShortBreakDuration() const;
	void setShortBreakDuration(uint32_t duration);

	uint32_t getLongBreakDuration() const;
	void setLongBreakDuration(uint32_t duration);

	uint32_t getLongBreakInterval() const;
	void setLongBreakInterval(uint32_t interval);

	bool isAutoStartShortBreak() const;
	void setAutoStartShortBreak(bool autoStart);

	bool isAutoStartLongBreak() const;
	void setAutoStartLongBreak(bool autoStart);

	bool isAutoStartPomodoro() const;
	void setAutoStartPomodoro(bool autoStart);

	bool isShortBreakNotification() const;
	void setShortBreakNotification(bool enabled);

	bool isLongBreakNotification() const;
	void setLongBreakNotification(bool enabled);

	bool isPomodoroNotification() const;
	void setPomodoroNotification(bool enabled);

	bool isAutoStartMusic() const;
	void setAutoStartMusic(bool autoStart);

	bool isAutoStartNextTask() const;
	void setAutoStartNextTask(bool autoStart);

private:
	mutable std::mutex m_mutex;
	std::string m_userId;
	std::string m_theme;
	std::string m_language;
	uint32_t m_pomodoroDuration;
	uint32_t m_shortBreakDuration;
	uint32_t m_longBreakDuration;
	uint32_t m_longBreakInterval;
	bool m_autoStartShortBreak;
	bool m_autoStartLongBreak;
	bool m_autoStartPomodoro;
	bool m_shortBreakNotification;
	bool m_longBreakNotification;
	bool m_pomodoroNotification;
	bool m_autoStartMusic;
	bool m_autoStartNextTask;
};

#endif // USERSETTINGSMODEL_H
