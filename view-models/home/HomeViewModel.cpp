/*
 * File: HomeViewModel.cpp
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for Home tab.
 */

#include "HomeViewModel.h"

#include <QDebug>

#include "view-models/pomodoro/PomodoroTitleViewModel.h"
#include "view-models/pomodoro/PomodoroViewModel.h"
#include "view-models/taskmanagement/TaskGroupsViewModel.h"
#include "view-models/taskmanagement/TasksViewModel.h"
#include "view-models/userprofile/UserProfileViewModel.h"

HomeViewModel::HomeViewModel(QObject *parent)
    : QObject(parent)
    , m_userProfileViewModel(std::make_unique<UserProfileViewModel>())
    , m_pomodoroViewModel(std::make_unique<PomodoroViewModel>())
    , m_pomodoroTitleViewModel(std::make_unique<PomodoroTitleViewModel>())
    , m_taskGroupsViewModel(std::make_unique<TaskGroupsViewModel>())
    , m_tasksViewModel(std::make_unique<TasksViewModel>())
{
	initDummyData();
}

HomeViewModel::~HomeViewModel()
{
	// Destructor implementation (if needed)
}

void HomeViewModel::initDummyData()
{
}

QObject *HomeViewModel::userProfile() const
{
	return m_userProfileViewModel.get();
}

void HomeViewModel::setUserProfile(QObject *userProfile)
{
	if (m_userProfileViewModel.get() != userProfile) {
		m_userProfileViewModel.reset(static_cast<UserProfileViewModel *>(userProfile));
		emit userProfileChanged();
	}
}

QObject *HomeViewModel::pomodoro() const
{
	return m_pomodoroViewModel.get();
}

void HomeViewModel::setPomodoro(QObject *pomodoro)
{
	if (m_pomodoroViewModel.get() != pomodoro) {
		m_pomodoroViewModel.reset(static_cast<PomodoroViewModel *>(pomodoro));
		emit pomodoroChanged();
	}
}

QObject *HomeViewModel::pomodoroTitle() const
{
	return m_pomodoroTitleViewModel.get();
}

void HomeViewModel::setPomodoroTitle(QObject *pomodoroTitle)
{
	if (m_pomodoroTitleViewModel.get() != pomodoroTitle) {
		m_pomodoroTitleViewModel.reset(static_cast<PomodoroTitleViewModel *>(pomodoroTitle));
		emit pomodoroTitleChanged();
	}
}

QObject *HomeViewModel::taskGroups() const
{
	return m_taskGroupsViewModel.get();
}

void HomeViewModel::setTaskGroups(QObject *taskGroups)
{
	if (m_taskGroupsViewModel.get() != taskGroups) {
		m_taskGroupsViewModel.reset(static_cast<TaskGroupsViewModel *>(taskGroups));
		emit taskGroupsChanged();
	}
}

QObject *HomeViewModel::tasks() const
{
	return m_tasksViewModel.get();
}

void HomeViewModel::setTasks(QObject *tasks)
{
	if (m_tasksViewModel.get() != tasks) {
		m_tasksViewModel.reset(static_cast<TasksViewModel *>(tasks));
		emit tasksChanged();
	}
}
