/**
 * File: PomodoroOpenApiController.h
 * Author: trung.la
 * Date: 09-02-2025
 * Description: Header file for PomodoroOpenApiController class that handles Pomodoro-related API endpoints.
 */

#pragma once

#include <string>
#include <httplib.h>

namespace gateway {
    
class PomodoroOpenApiController {
public:
    /**
     * @brief Registers all Pomodoro-related routes on the given server with the specified base URL.
     * 
     * @param server Reference to the httplib::Server instance where routes will be registered.
     * @param baseUrl The base URL prefix for all Pomodoro routes.
     */
    static void registerRoutes(httplib::Server& server, const std::string& baseUrl);
};

} // namespace gateway
