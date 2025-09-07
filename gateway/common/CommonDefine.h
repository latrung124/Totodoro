/**
 * @file CommonDefine.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Common definitions and constants used across the gateway module.
 */

#pragma once

#include <stdint.h>

namespace gateway {

enum class RouteHandlerType : uint8_t
{
    Session,
    Task,
    User,
    Notification
};

}