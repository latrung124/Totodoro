/*
* File: Utils.h
* Author: trung.la
* Date: 06-08-2025
* Description: This file defines utility functions for the UserProfileService, including string manipulation and error handling.
*/

#ifndef USER_PROFILE_UTILS_H
#define USER_PROFILE_UTILS_H

#include <string>

namespace user_profile
{

namespace utils
{

namespace endpoint
{
    constexpr const char* kCreateUser = "/users/create";
    constexpr const char* kUpdateUser = "/users/update";
    constexpr const char* kGetUser = "/users/get";
} // namespace user_profile::utils::endpoint

} // namespace user_profile::utils

} // namespace user_profile

#endif // USER_PROFILE_UTILS_H