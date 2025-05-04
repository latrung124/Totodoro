/*
 * File: HomeViewModel.cpp
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for Home tab.
 */

#include "HomeViewModel.h"

#include "view-models/taskmanagement/TaskGroupsViewModel.h"
#include "view-models/userprofile/UserProfileViewModel.h"

HomeViewModel::HomeViewModel(QObject *parent)
    : QObject(parent)
    , m_userProfileViewModel(std::make_unique<UserProfileViewModel>())
    , m_taskGroupsViewModel(std::make_unique<TaskGroupsViewModel>())
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
