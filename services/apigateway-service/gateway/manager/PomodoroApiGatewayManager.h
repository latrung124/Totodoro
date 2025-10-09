/**
 * @file PomodoroApiGatewayManager.h
 * @author trung.la
 * @date 09-24-2025
 * @brief This file contains the declaration of the PomodoroApiGatewayManager class.
 */

#pragma once

#include <map>
#include <memory>

#include "IApiGatewayManager.h"

namespace gateway {
struct PomodoroSessionProperties;
struct ApiResponse;
} // namespace gateway

class JsonResponseHandler;

class PomodoroApiGatewayManager : public IApiGatewayManager
{
	Q_OBJECT

public:
	using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
	using ResponseCallback = std::function<void(const ApiResponsePtr &)>;
	using PomodoroSessionContainer = std::vector<gateway::PomodoroSessionProperties>;
	using JsonResponseHandlerPtr = std::shared_ptr<JsonResponseHandler>;

	explicit PomodoroApiGatewayManager(QObject *parent = nullptr);
	~PomodoroApiGatewayManager() override = default;

	bool registerResponseCallback(
	    gateway::RequestType requestType, const ResponseCallback &callback) override;
	bool unregisterResponseCallback(gateway::RequestType requestType) override;

	void request(const gateway::ApiRequest &request) override;

private:
	bool createPomodoroSession(const gateway::PomodoroSessionProperties &sessionProps);
	bool getPomodoroSessions(const std::string &userId, const std::string &taskId);
	bool updatePomodoroSession(const gateway::PomodoroSessionProperties &sessionProps);
	bool deletePomodoroSession(const std::string &sessionId);

	std::map<gateway::RequestType, ResponseCallback> m_responseCallbacks;
	JsonResponseHandlerPtr m_responseHandler;
};
