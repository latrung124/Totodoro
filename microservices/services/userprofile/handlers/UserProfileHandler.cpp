/*
* File: UserProfileHandler.cpp
* Author: trung.la
* Date: 05-28-2025
* Description: This file implements the UserProfileHandler class, which is responsible for handling user-related operations in the microservices architecture.
*/

#include "microservices/services/userprofile/handlers/UserProfileHandler.h"

#include "user_service.pb.h"

#include "microservices/services/userprofile/models/User.h"
#include "microservices/services/useprofile/repositories/SQLiteUserRepository.h"

UserProfileHandler::UserProfileHandler(UserRepositoryUPtr userRepository)
    : m_userRepository(std::move(userRepository))
{
}

UserProfileHandler::~UserProfileHandler()
{
}

User UserProfileHandler::createUser(CreateUserRequest const &request)
{
    if (!m_userRepository)
    {
        throw std::runtime_error("User repository is not initialized.");
        return User(); // This line is unreachable but added to satisfy the compiler.
    }

    User user;
    user.setUserName(request.username());
    user.setEmail(request.email());

    m_userRepository->insert(user);

    return user;
}