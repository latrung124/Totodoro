/**
 * @file UserSettingsModel.cpp
 * @author trung.la
 * @date 10-29-2025
 * @brief This file contains the implementation of the UserSettingsModel class.
 */

#include "models/userprofile/UserSettingsModel.h"

#include <QMetaObject>
#include <QString>

#include "core/controllers/ViewModelController.h"
#include "view-models/userprofile/UserSettingsViewModel.h"

UserSettingsModel::UserSettingsModel()
    : DatabaseModel()
{
}

UserSettingsModel::~UserSettingsModel()
{
}

std::string UserSettingsModel::getUserId() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_userId;
}

void UserSettingsModel::setUserId(const std::string &userId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_userId != userId) {
		m_userId = userId;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onUserIdChanged", Q_ARG(QString, QString::fromStdString(m_userId)));
	}
}

std::string UserSettingsModel::getTheme() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_theme;
}

void UserSettingsModel::setTheme(const std::string &theme)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_theme != theme) {
		m_theme = theme;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onThemeChanged", Q_ARG(QString, QString::fromStdString(m_theme)));
	}
}

std::string UserSettingsModel::getLanguage() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_language;
}

void UserSettingsModel::setLanguage(const std::string &language)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_language != language) {
		m_language = language;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onLanguageChanged", Q_ARG(QString, QString::fromStdString(m_language)));
	}
}

uint32_t UserSettingsModel::getPomodoroDuration() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_pomodoroDuration;
}

void UserSettingsModel::setPomodoroDuration(uint32_t duration)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_pomodoroDuration != duration) {
		m_pomodoroDuration = duration;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onPomodoroDurationChanged", Q_ARG(uint32_t, m_pomodoroDuration));
	}
}

uint32_t UserSettingsModel::getShortBreakDuration() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_shortBreakDuration;
}

void UserSettingsModel::setShortBreakDuration(uint32_t duration)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_shortBreakDuration != duration) {
		m_shortBreakDuration = duration;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onShortBreakDurationChanged", Q_ARG(uint32_t, m_shortBreakDuration));
	}
}

uint32_t UserSettingsModel::getLongBreakDuration() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_longBreakDuration;
}

void UserSettingsModel::setLongBreakDuration(uint32_t duration)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_longBreakDuration != duration) {
		m_longBreakDuration = duration;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onLongBreakDurationChanged", Q_ARG(uint32_t, m_longBreakDuration));
	}
}

uint32_t UserSettingsModel::getLongBreakInterval() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_longBreakInterval;
}

void UserSettingsModel::setLongBreakInterval(uint32_t interval)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_longBreakInterval != interval) {
		m_longBreakInterval = interval;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onLongBreakIntervalChanged", Q_ARG(uint32_t, m_longBreakInterval));
	}
}

bool UserSettingsModel::isAutoStartShortBreak() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_autoStartShortBreak;
}

void UserSettingsModel::setAutoStartShortBreak(bool autoStart)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_autoStartShortBreak != autoStart) {
		m_autoStartShortBreak = autoStart;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAutoStartShortBreakChanged", Q_ARG(bool, m_autoStartShortBreak));
	}
}

bool UserSettingsModel::isAutoStartLongBreak() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_autoStartLongBreak;
}

void UserSettingsModel::setAutoStartLongBreak(bool autoStart)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_autoStartLongBreak != autoStart) {
		m_autoStartLongBreak = autoStart;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAutoStartLongBreakChanged", Q_ARG(bool, m_autoStartLongBreak));
	}
}

bool UserSettingsModel::isAutoStartPomodoro() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_autoStartPomodoro;
}

void UserSettingsModel::setAutoStartPomodoro(bool autoStart)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_autoStartPomodoro != autoStart) {
		m_autoStartPomodoro = autoStart;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAutoStartPomodoroChanged", Q_ARG(bool, m_autoStartPomodoro));
	}
}

bool UserSettingsModel::isShortBreakNotification() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_shortBreakNotification;
}

void UserSettingsModel::setShortBreakNotification(bool enabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_shortBreakNotification != enabled) {
		m_shortBreakNotification = enabled;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onShortBreakNotificationChanged", Q_ARG(bool, m_shortBreakNotification));
	}
}

bool UserSettingsModel::isLongBreakNotification() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_longBreakNotification;
}

void UserSettingsModel::setLongBreakNotification(bool enabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_longBreakNotification != enabled) {
		m_longBreakNotification = enabled;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onLongBreakNotificationChanged", Q_ARG(bool, m_longBreakNotification));
	}
}

bool UserSettingsModel::isPomodoroNotification() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_pomodoroNotification;
}

void UserSettingsModel::setPomodoroNotification(bool enabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_pomodoroNotification != enabled) {
		m_pomodoroNotification = enabled;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onPomodoroNotificationChanged", Q_ARG(bool, m_pomodoroNotification));
	}
}

bool UserSettingsModel::isAutoStartMusic() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_autoStartMusic;
}

void UserSettingsModel::setAutoStartMusic(bool autoStart)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_autoStartMusic != autoStart) {
		m_autoStartMusic = autoStart;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAutoStartMusicChanged", Q_ARG(bool, m_autoStartMusic));
	}
}

bool UserSettingsModel::isAutoStartNextTask() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_autoStartNextTask;
}

void UserSettingsModel::setAutoStartNextTask(bool autoStart)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_autoStartNextTask != autoStart) {
		m_autoStartNextTask = autoStart;
	}

	auto viewModel = ViewModelController::getInstance().userSettingsViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAutoStartNextTaskChanged", Q_ARG(bool, m_autoStartNextTask));
	}
}
