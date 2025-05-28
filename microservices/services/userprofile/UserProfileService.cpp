/*
* File: UserProfileService.cpp
* Author: trung.la
* Date: 05-28-2025
* Description: This file implements the UserProfileService class, which is responsible for managing user profiles in the microservices architecture.
*/

#include "microservices/services/userprofile/UserProfileService.h"

#include <iostream>

#include <user_service.pb.h>

#include "microservices/services/userprofile/models/User.h"
#include "microservices/services/userprofile/handlers/UserProfileHandler.h"
#include "microservices/services/userprofile/repositories/SQLiteUserRepository.h"

UserProfileService::UserProfileService(int port, IUserRepositoryUPtr userRepository)
    : m_port(port), m_userRepository(std::move(userRepository))
{
    m_userProfileHandler = std::make_unique<UserProfileHandler>(std::move(m_userRepository));
}

void UserProfileService::start()
{
    /**
     * Define an HTTP Post route at /users
     * Lambda function is the request handler for this route
     */
    m_server.Post("/users", [&](const httplib::Request& req, httplib::Response& res) {
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

    std::cout << "user service listening on port " << m_port << std::endl;

    // Start the server listening on localhost and the specified port
    m_server.listen("localhost", m_port);
}