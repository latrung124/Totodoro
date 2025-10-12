/**
 * @file common/ApiResponse.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the ApiResponse struct.
 */

#pragma once

#include <qjsonobject.h>
#include <string>
#include <variant>

#include "common/UserProperties.h"
#include "common/TaskProperties.h"
#include "common/PomodoroProperties.h"

#include "common/CommonDefine.h"

namespace gateway
{

struct ApiResponse
{
    RequestType requestType;
    bool success;
    int statusCode;
    std::string body;
    std::variant<std::monostate, UserProperties, TaskProperties, PomodoroSessionProperties, std::string> data;

    template<typename T>
    T getData() const
    {
        if (RequestType::Unknown == requestType)
        {
            throw std::runtime_error("RequestType is Unknown");
        }

        if (RequestType::CreateUser == requestType || RequestType::GetUserProperties == requestType || RequestType::UpdateUserProperties == requestType)
        {
            if (!std::holds_alternative<UserProperties>(data))
            {
                throw std::bad_variant_access();
            }
            return std::get<UserProperties>(data);
        }
        else if (RequestType::CreateTask == requestType || RequestType::GetTasks == requestType || RequestType::UpdateTask == requestType)
        {
            if (!std::holds_alternative<TaskProperties>(data))
            {
                throw std::bad_variant_access();
            }
            return std::get<TaskProperties>(data);
        }
        else if (RequestType::CreatePomodoroSession == requestType || RequestType::GetPomodoroSessions == requestType || RequestType::UpdatePomodoroSession == requestType)
        {
            if (!std::holds_alternative<PomodoroSessionProperties>(data))
            {
                throw std::bad_variant_access();
            }
            return std::get<PomodoroSessionProperties>(data);
        }
        
        if (std::holds_alternative<T>(data))
        {
            return std::get<T>(data);
        }
        throw std::bad_variant_access();
    }

    ApiResponse() : success(false), statusCode(0), body("") {}
};

} // namespace gateway
