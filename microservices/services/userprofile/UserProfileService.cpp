/*
* File: UserProfileService.cpp
* Author: trung.la
* Date: 05-28-2025
* Description: This file implements the UserProfileService class, which is responsible for managing user profiles in the microservices architecture.
*/

#include "UserProfileService.h"

#include <iostream>

#include <user_service.pb.h>

#include "User.h"
#include "UserProfileHandler.h"
#include "SQLiteUserRepository.h"
#include "Utils.h"

UserProfileService::UserProfileService(int port, IUserRepositoryUPtr userRepository)
    : m_port(port), m_userRepository(std::move(userRepository))
{
    m_userProfileHandler = std::make_unique<UserProfileHandler>(std::move(m_userRepository));
}

void UserProfileService::start()
{
    // TODO: Register the service with a service discovery mechanism
    // Register Endpoints
    registerEndpoints();
    std::cout << "user service listening on port " << m_port << std::endl;

    // Start the server listening on localhost and the specified port
    m_server.listen("localhost", m_port);
}

void UserProfileService::stop()
{
    std::cout << "Stopping user service..." << std::endl;
    m_server.stop();
    std::cout << "User service stopped." << std::endl;
}

void UserProfileService::registerEndpoints()
{
    m_server.Post(user_profile::utils::endpoint::kCreateUser, [&](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Received POST request to create user!" << std::endl;

        user_service::CreateUserRequest request;
        try {
            request.ParseFromString(req.body);
        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content("Invalid request body", "text/plain");
            return;
        }

        User user = m_userProfileHandler->createUser(request);
        user_service::User userProto;
        userProto.set_username(user.getUserName());
        userProto.set_email(user.getEmail());
        res.set_content(userProto.SerializeAsString(), "application/protobuf");

        std::cout << "User created successfully!" << std::endl;
    });

    m_server.Put(user_profile::utils::endpoint::kUpdateUser, [&](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Received PUT request to update user!" << std::endl;

        user_service::UpdateUserRequest request;
        try {
            request.ParseFromString(req.body);
        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content("Invalid request body", "text/plain");
            return;
        }

        User user;
        user.setUserId(request.user_id());
        user.setUserName(request.username());
        user.setEmail(request.email());
        user.setUpdateAt(""); //TODO: update get current time method later

        m_userProfileHandler->updateUser(user);
        res.status = 204; // No Content
        std::cout << "User updated successfully!" << std::endl;
    });

    m_server.Get(user_profile::utils::endpoint::kGetUser, [&](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Received GET request to retrieve user!" << std::endl;

        std::string userId = req.get_param_value("user_id");
        if (userId.empty()) {
            res.status = 400;
            res.set_content("Missing user_id parameter", "text/plain");
            return;
        }

        User user;
        user.setUserId(userId);
        m_userProfileHandler->getUser(user);

        auto userOpt = m_userProfileHandler->getUser(user);
        if (userOpt) {
            user_service::User userProto;
            userProto.set_user_id(userOpt->getUserId());
            userProto.set_username(userOpt->getUserName());
            userProto.set_email(userOpt->getEmail());
            res.set_content(userProto.SerializeAsString(), "application/protobuf");
        } else {
            res.status = 404;
            res.set_content("User not found", "text/plain");
        }

        std::cout << "User retrieved successfully!" << std::endl;
    });
}
