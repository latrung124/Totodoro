/**
 * @file UserInformationModel.h
 * @author trung.la
 * @date 10-28-2025
 * @brief This file contains the declaration of the UserInformationModel class.
 */

#ifndef USERINFORMATIONMODEL_H
#define USERINFORMATIONMODEL_H

#include "models/DatabaseModel.h"

#include <mutex>
#include <string>

class UserInformationModel : public DatabaseModel
{
public:
	UserInformationModel();
	~UserInformationModel();

	// Getters and setters for user information
	std::string getUserId() const;
	void setUserId(const std::string &userId);

	std::string getUsername() const;
	void setUsername(const std::string &username);

	std::string getEmail() const;
	void setEmail(const std::string &email);

	std::string getAvatarUrl() const;
	void setAvatarUrl(const std::string &url);

	// TODO: Other member functions as needed

private:
	std::string m_userId;
	std::string m_username;
	std::string m_email;
	std::string m_avatarUrl;

	// Mutex for thread-safe access
	mutable std::mutex mutex;
};

#endif // USERINFORMATIONMODEL_H
