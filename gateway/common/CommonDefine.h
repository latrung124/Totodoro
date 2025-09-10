/**
 * @file CommonDefine.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Common definitions and constants used across the gateway module.
 */

#pragma once

#include <stdint.h>
#include <string_view>

namespace gateway {

constexpr std::string_view kBaseUrl = "http://localhost:8081";

enum class RouteType : uint8_t
{
    Session,
    Task,
    User,
    Notification
};

}