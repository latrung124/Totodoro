/**
 * @file UserSettingsViewModel.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsViewModel class.
 */

#include "UserSettingsViewModel.h"

UserSettingsViewModel::UserSettingsViewModel(QObject *parent)
    : QObject(parent)
    , m_userId("")
    , m_theme("light")
    , m_language("en")
    , m_pomodoroDuration(25)
    , m_shortBreakDuration(5)
    , m_longBreakDuration(15)
    , m_longBreakInterval(4)
    , m_autoStartShortBreak(false)
    , m_autoStartLongBreak(false)
    , m_autoStartPomodoro(false)
    , m_shortBreakNotification(true)
    , m_longBreakNotification(true)
    , m_pomodoroNotification(true)
    , m_autoStartMusic(false)
    , m_autoStartNextTask(false)
{
}

UserSettingsViewModel::~UserSettingsViewModel()
{
}

QString UserSettingsViewModel::userId() const
{
	return m_userId;
}

void UserSettingsViewModel::setUserId(const QString &userId)
{
	if (m_userId != userId) {
		m_userId = userId;
		emit userIdChanged(m_userId);
	}
}

QString UserSettingsViewModel::theme() const
{
	return m_theme;
}

void UserSettingsViewModel::setTheme(const QString &theme)
{
	if (m_theme != theme) {
		m_theme = theme;
		emit themeChanged(m_theme);
	}
}

QString UserSettingsViewModel::language() const
{
	return m_language;
}

void UserSettingsViewModel::setLanguage(const QString &language)
{
	if (m_language != language) {
		m_language = language;
		emit languageChanged(m_language);
	}
}

uint32_t UserSettingsViewModel::pomodoroDuration() const
{
	return m_pomodoroDuration;
}

void UserSettingsViewModel::setPomodoroDuration(uint32_t duration)
{
	if (m_pomodoroDuration != duration) {
		m_pomodoroDuration = duration;
		emit pomodoroDurationChanged(m_pomodoroDuration);
	}
}

uint32_t UserSettingsViewModel::shortBreakDuration() const
{
	return m_shortBreakDuration;
}

void UserSettingsViewModel::setShortBreakDuration(uint32_t duration)
{
	if (m_shortBreakDuration != duration) {
		m_shortBreakDuration = duration;
		emit shortBreakDurationChanged(m_shortBreakDuration);
	}
}

uint32_t UserSettingsViewModel::longBreakDuration() const
{
	return m_longBreakDuration;
}

void UserSettingsViewModel::setLongBreakDuration(uint32_t duration)
{
	if (m_longBreakDuration != duration) {
		m_longBreakDuration = duration;
		emit longBreakDurationChanged(m_longBreakDuration);
	}
}

uint32_t UserSettingsViewModel::longBreakInterval() const
{
	return m_longBreakInterval;
}

void UserSettingsViewModel::setLongBreakInterval(uint32_t interval)
{
	if (m_longBreakInterval != interval) {
		m_longBreakInterval = interval;
		emit longBreakIntervalChanged(m_longBreakInterval);
	}
}

bool UserSettingsViewModel::autoStartShortBreak() const
{
	return m_autoStartShortBreak;
}

void UserSettingsViewModel::setAutoStartShortBreak(bool autoStart)
{
	if (m_autoStartShortBreak != autoStart) {
		m_autoStartShortBreak = autoStart;
		emit autoStartShortBreakChanged(m_autoStartShortBreak);
	}
}

bool UserSettingsViewModel::autoStartLongBreak() const
{
	return m_autoStartLongBreak;
}

void UserSettingsViewModel::setAutoStartLongBreak(bool autoStart)
{
	if (m_autoStartLongBreak != autoStart) {
		m_autoStartLongBreak = autoStart;
		emit autoStartLongBreakChanged(m_autoStartLongBreak);
	}
}

bool UserSettingsViewModel::autoStartPomodoro() const
{
	return m_autoStartPomodoro;
}

void UserSettingsViewModel::setAutoStartPomodoro(bool autoStart)
{
	if (m_autoStartPomodoro != autoStart) {
		m_autoStartPomodoro = autoStart;
		emit autoStartPomodoroChanged(m_autoStartPomodoro);
	}
}

bool UserSettingsViewModel::shortBreakNotification() const
{
	return m_shortBreakNotification;
}

void UserSettingsViewModel::setShortBreakNotification(bool enabled)
{
	if (m_shortBreakNotification != enabled) {
		m_shortBreakNotification = enabled;
		emit shortBreakNotificationChanged(m_shortBreakNotification);
	}
}

bool UserSettingsViewModel::longBreakNotification() const
{
	return m_longBreakNotification;
}

void UserSettingsViewModel::setLongBreakNotification(bool enabled)
{
	if (m_longBreakNotification != enabled) {
		m_longBreakNotification = enabled;
		emit longBreakNotificationChanged(m_longBreakNotification);
	}
}

bool UserSettingsViewModel::pomodoroNotification() const
{
	return m_pomodoroNotification;
}

void UserSettingsViewModel::setPomodoroNotification(bool enabled)
{
	if (m_pomodoroNotification != enabled) {
		m_pomodoroNotification = enabled;
		emit pomodoroNotificationChanged(m_pomodoroNotification);
	}
}

bool UserSettingsViewModel::autoStartMusic() const
{
	return m_autoStartMusic;
}

void UserSettingsViewModel::setAutoStartMusic(bool autoStart)
{
	if (m_autoStartMusic != autoStart) {
		m_autoStartMusic = autoStart;
		emit autoStartMusicChanged(m_autoStartMusic);
	}
}

bool UserSettingsViewModel::autoStartNextTask() const
{
	return m_autoStartNextTask;
}

void UserSettingsViewModel::setAutoStartNextTask(bool autoStart)
{
	if (m_autoStartNextTask != autoStart) {
		m_autoStartNextTask = autoStart;
		emit autoStartNextTaskChanged(m_autoStartNextTask);
	}
}

void UserSettingsViewModel::onUserIdChanged(const QString &userId)
{
	setUserId(userId);
}

void UserSettingsViewModel::onThemeChanged(const QString &theme)
{
	setTheme(theme);
}

void UserSettingsViewModel::onLanguageChanged(const QString &language)
{
	setLanguage(language);
}

void UserSettingsViewModel::onPomodoroDurationChanged(uint32_t duration)
{
	setPomodoroDuration(duration);
}

void UserSettingsViewModel::onShortBreakDurationChanged(uint32_t duration)
{
	setShortBreakDuration(duration);
}

void UserSettingsViewModel::onLongBreakDurationChanged(uint32_t duration)
{
	setLongBreakDuration(duration);
}

void UserSettingsViewModel::onLongBreakIntervalChanged(uint32_t interval)
{
	setLongBreakInterval(interval);
}

void UserSettingsViewModel::onAutoStartShortBreakChanged(bool autoStart)
{
	setAutoStartShortBreak(autoStart);
}

void UserSettingsViewModel::onAutoStartLongBreakChanged(bool autoStart)
{
	setAutoStartLongBreak(autoStart);
}

void UserSettingsViewModel::onAutoStartPomodoroChanged(bool autoStart)
{
	setAutoStartPomodoro(autoStart);
}

void UserSettingsViewModel::onShortBreakNotificationChanged(bool enabled)
{
	setShortBreakNotification(enabled);
}

void UserSettingsViewModel::onLongBreakNotificationChanged(bool enabled)
{
	setLongBreakNotification(enabled);
}

void UserSettingsViewModel::onPomodoroNotificationChanged(bool enabled)
{
	setPomodoroNotification(enabled);
}

void UserSettingsViewModel::onAutoStartMusicChanged(bool autoStart)
{
	setAutoStartMusic(autoStart);
}

void UserSettingsViewModel::onAutoStartNextTaskChanged(bool autoStart)
{
	setAutoStartNextTask(autoStart);
}
