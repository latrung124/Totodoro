/**
 * File: PomodoroOpenApiController.h
 * Author: trung.la
 * Date: 09-02-2025
 * Description: Header file for PomodoroOpenApiController class that handles Pomodoro-related API endpoints.
 */

#pragma once

#include <string>
#include <memory>

#include <httplib.h>

#include "RequestRouter.h"

class AsyncRequestProcessor;

namespace gateway {

class PomodoroOpenApiController {
public:
    using AsyncRequestProcessorPtr = std::shared_ptr<AsyncRequestProcessor>;

    PomodoroOpenApiController(AsyncRequestProcessorPtr requestProcessor,
                              const std::string& baseUrl);

    ~PomodoroOpenApiController() = default;

    /**
     * @brief Registers all Pomodoro-related routes on the given server with the specified base URL.
     * 
     * @param server Reference to the httplib::Server instance where routes will be registered.
     */
    void registerRoutes(httplib::Server& server);

private:
    /**
     * @brief Initializes route handlers for Pomodoro-related endpoints.
     * 
     * @param requestProcessor Shared pointer to the AsyncRequestProcessor for handling asynchronous requests.
     * @param apiClientFactory Shared pointer to the ApiClientFactory for creating API clients.
     * @param baseUrl Base URL for the Pomodoro API endpoints.
     */
    void initializeHandlers(AsyncRequestProcessorPtr requestProcessor,
                            const std::string& baseUrl);

    RequestRouter mRouter;
};

} // namespace gateway
