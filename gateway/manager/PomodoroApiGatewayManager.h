/**
 * @file PomodoroApiGatewayManager.h
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the declaration of the PomodoroApiGatewayManager class.
 */

#pragma once

#include <string>
#include <memory>
#include <functional>

#include "IApiGatewayManager.h"

namespace gateway
{
    struct PomodoroSessionProperties;
    
    struct ApiResponse;
}

class PomodoroApiGatewayManager : public IApiGatewayManager
{
public:
    using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
    using ResponseCallback = std::function<void(const ApiResponsePtr&)>;
    using ErrorCallback = std::function<void(const std::string&)>;
    using PomodoroSessionContainer = std::vector<gateway::PomodoroSessionProperties>;

    PomodoroApiGatewayManager() = default;
    ~PomodoroApiGatewayManager() override = default;

    bool onCreatePomodoroSession(const gateway::PomodoroSessionProperties& sessionProps,
                                 const ResponseCallback& onSuccess,
                                 const ErrorCallback& onError);

    bool onGetPomodoroSessions(const std::string& userId,
                               PomodoroSessionContainer& outSessions,
                               const ResponseCallback& onSuccess,
                               const ErrorCallback& onError);
    
    bool onUpdatePomodoroSession(const gateway::PomodoroSessionProperties& sessionProps,
                                 const ResponseCallback& onSuccess,
                                 const ErrorCallback& onError);

    bool onDeletePomodoroSession(const std::string& sessionId,
                                 const ResponseCallback& onSuccess,
                                 const ErrorCallback& onError);
};