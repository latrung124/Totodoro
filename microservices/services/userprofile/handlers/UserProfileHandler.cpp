/*
* File: UserProfileHandler.cpp
* Author: trung.la
* Date: 05-28-2025
* Description: This file implements the UserProfileHandler class, which is responsible for handling user-related operations in the microservices architecture.
*/

#include "UserProfileHandler.h"

#include "user_service.pb.h"

#include "User.h"
#include "SQLiteUserRepository.h"

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

void UserProfileHandler::updateUser(User const &user)
{
    if (!m_userRepository) {
        throw std::runtime_error("User repository is not initialized.");
        return;
    }

    m_userRepository->update(user);
}

std::optional<User> UserProfileHandler::getUser(User const &user)
{
    if (!m_userRepository) {
        throw std::runtime_error("User repository is not initialized.");
        return std::nullopt;
    }

    if (!user.getUserId().empty()) {
        return m_userRepository->findById(user.getUserId());
    }

    if (!user.getEmail().empty()) {
        return m_userRepository->findByEmail(user.getEmail());
    }

    if (!user.getUserName().empty()) {
        return m_userRepository->findByUserName(user.getUserName());
    }

    return std::nullopt; // No valid identifier provided
}
