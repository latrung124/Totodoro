/*
 * File: main.cpp
 * Author: trung.la
 * Date: 05-28-2025
 * Description: This file contains the main function for the UserProfileService microservice, which
 * initializes and starts the service.
 */

#include <iostream>

#include "connection/SQLiteConnection.h"
#include "SQLiteUserRepository.h"
#include "UserProfileHandler.h"
#include "UserProfileService.h"

int main()
{
	std::cout << "Starting UserProfileService..." << std::endl;

	auto dbConnection = std::make_shared<SQLiteConnection>(
	    std::string(DB_SOURCE_PATH) + "/UserProfile.db");
	auto repository = std::make_unique<SQLiteUserRepository>(dbConnection);

	UserProfileService service(50051, std::move(repository));
	service.start();

	return EXIT_SUCCESS;
}
