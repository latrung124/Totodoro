/*
* File: UserProfileService.h
* Author: trung.la
* Date: 05-28-2025
* Description: This file defines the UserProfileService class, which is responsible for managing user profiles in the microservices architecture.
*/

#ifndef USER_PROFILE_SERVICE_H
#define USER_PROFILE_SERVICE_H

#include <memory>
#include <httplib.h>

class IUserRepository;
class UserProfileHandler;

class UserProfileService
{
public:
    using IUserRepositoryUPtr = std::unique_ptr<IUserRepository>;
    using UserProfileHandlerUPtr = std::unique_ptr<UserProfileHandler>;

    UserProfileService(int port, IUserRepositoryUPtr userRepository);
    ~UserProfileService() = default;

    void start();

private:
    int m_port;

    httplib::Server m_server;
    IUserRepositoryUPtr m_userRepository;
    UserProfileHandlerUPtr m_userProfileHandler;
};

#endif // USER_PROFILE_SERVICE_H