/*
 * File: main.cpp
 * Author: trung.la
 * Date: 05-28-2025
 * Description: This file contains the main function for the UserProfileService microservice, which
 * initializes and starts the service.
 */

#include <iostream>

#include "microservices/connection/SQLiteConnection.h"
#include "microservices/services/userprofile/handlers/UserProfileHandler.h"
#include "microservices/services/userprofile/UserProfileService.h"

int main()
{
	std::cout << "Starting UserProfileService..." << std::endl;

	auto dbConnection = std::make_shared<SQLiteConnection>(
	    std::string(DB_SOURCE_PATH) + "/UserProfile.db");
	auto repository = std::make_unique<SQLiteUserRepository>(dbConnection);

	UserService service(50051, std::move(repository));
	service.start();

	return EXIT_SUCCESS;
}
