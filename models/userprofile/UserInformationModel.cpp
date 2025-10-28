/**
 * @file UserInformationModel.cpp
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the implementation of the UserInformationModel class.
 */

#include "models/userprofile/UserInformationModel.h"

#include <QMetaObject>
#include <QString>

#include "core/controllers/ViewModelController.h"
#include "view-models/userprofile/UserProfileViewModel.h"

UserInformationModel::UserInformationModel() = default;

UserInformationModel::~UserInformationModel() = default;

std::string UserInformationModel::getUsername() const
{
	std::lock_guard<std::mutex> lock(mutex);
	return m_username;
}

void UserInformationModel::setUsername(const std::string &username)
{
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (m_username != username) {
			m_username = username;
		}

		auto viewModel = ViewModelController::getInstance().userProfileViewModel();
		if (viewModel) {
			QMetaObject::invokeMethod(
			    viewModel,
			    "onDisplayNameChanged",
			    Q_ARG(QString, QString::fromStdString(m_username)));
		}
	}
}

std::string UserInformationModel::getEmail() const
{
	std::lock_guard<std::mutex> lock(mutex);
	return m_email;
}

void UserInformationModel::setEmail(const std::string &email)
{
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (m_email != email) {
			m_email = email;
		}

		auto viewModel = ViewModelController::getInstance().userProfileViewModel();
		if (viewModel) {
			QMetaObject::invokeMethod(
			    viewModel, "onEmailChanged", Q_ARG(QString, QString::fromStdString(m_email)));
		}
	}
}

std::string UserInformationModel::getAvatarUrl() const
{
	std::lock_guard<std::mutex> lock(mutex);
	return m_avatarUrl;
}

void UserInformationModel::setAvatarUrl(const std::string &url)
{
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (m_avatarUrl != url) {
			m_avatarUrl = url;
		}

		auto viewModel = ViewModelController::getInstance().userProfileViewModel();
		if (viewModel) {
			QMetaObject::invokeMethod(
			    viewModel,
			    "onAvatarUrlChanged",
			    Q_ARG(QString, QString::fromStdString(m_avatarUrl)));
		}
	}
}
