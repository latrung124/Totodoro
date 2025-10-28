/*
 * File: UserProfileViewModel.cpp
 * Author: trung.la
 * Date: 04-30-2025
 * Description: View Model for TaskGroups.
 */

#include "UserProfileViewModel.h"

UserProfileViewModel::UserProfileViewModel(QObject *parent)
    : QObject(parent)
{
}

UserProfileViewModel::~UserProfileViewModel()
{
}

QString UserProfileViewModel::displayName() const
{
	return m_displayName;
}

void UserProfileViewModel::setDisplayName(const QString &displayName)
{
	if (m_displayName != displayName) {
		m_displayName = displayName;
		emit displayNameChanged(m_displayName);
	}
}

QString UserProfileViewModel::avatarUrl() const
{
	return m_avatarUrl;
}

void UserProfileViewModel::setAvatarUrl(const QString &avatarUrl)
{
	if (m_avatarUrl != avatarUrl) {
		m_avatarUrl = avatarUrl;
		emit avatarUrlChanged(m_avatarUrl);
	}
}

QString UserProfileViewModel::email() const
{
	return m_email;
}

void UserProfileViewModel::setEmail(const QString &email)
{
	if (m_email != email) {
		m_email = email;
		emit emailChanged(m_email);
	}
}

void UserProfileViewModel::onDisplayNameChanged(const QString &displayName)
{
	setDisplayName(displayName);
}

void UserProfileViewModel::onAvatarUrlChanged(const QString &avatarUrl)
{
	setAvatarUrl(avatarUrl);
}

void UserProfileViewModel::onEmailChanged(const QString &email)
{
	setEmail(email);
}
