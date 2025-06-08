/*
* File: UserProfileHandler.h
* Author: trung.la
* Date: 05-28-2025
* Description: This file defines the UserProfileHandler class, which is responsible for handling user-related operations in the microservices architecture.
*/

#ifndef USER_HANDLER_H
#define USER_HANDLER_H

#include <memory>
#include <optional>

class User;
class IUserRepository;

namespace user_service
{
    class CreateUserRequest;
} // namespace user_service

class UserProfileHandler
{
public:
    using UserRepositoryUPtr = std::unique_ptr<IUserRepository>;
    using CreateUserRequest = user_service::CreateUserRequest;

    UserProfileHandler(UserRepositoryUPtr userRepository);
    ~UserProfileHandler();

    User createUser(CreateUserRequest const &request);
    void updateUser(User const &user);
    std::optional<User> getUser(User const &user);

private:
    UserRepositoryUPtr m_userRepository;
};

#endif // USER_HANDLER_H