/**
 * @file PomodoroApiGatewayManager.h
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the declaration of the PomodoroApiGatewayManager class.
 */

#pragma once

#include <map>

#include "IApiGatewayManager.h"

namespace gateway
{
    struct PomodoroSessionProperties;
    struct ApiResponse;
}

class PomodoroApiGatewayManager : public IApiGatewayManager
{
    Q_OBJECT
public:
    using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
    using ResponseCallback = std::function<void(const ApiResponsePtr&)>;
    using PomodoroSessionContainer = std::vector<gateway::PomodoroSessionProperties>;

    explicit PomodoroApiGatewayManager(QObject* parent = nullptr) : IApiGatewayManager(parent) {}
    ~PomodoroApiGatewayManager() override = default;

    bool registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback) override;
    bool unregisterResponseCallback(gateway::RequestType requestType) override;

    bool createPomodoroSession(const gateway::PomodoroSessionProperties& sessionProps);
    bool getPomodoroSessions(const std::string& userId, const std::string& taskId);
    bool updatePomodoroSession(const gateway::PomodoroSessionProperties& sessionProps);
    bool deletePomodoroSession(const std::string& sessionId);

private:
    std::map<gateway::RequestType, ResponseCallback> m_responseCallbacks;
};
