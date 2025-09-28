/**
 * @file UserApiGatewayManager.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the UserApiGatewayManager class.
 */

#pragma once

#include <map>

#include "IApiGatewayManager.h"

namespace gateway
{
    struct UserProperties;
    struct UserSettings;
    struct ApiResponse;
}

class UserApiGatewayManager : public IApiGatewayManager
{
public:
    using ApiResponsePtr = std::shared_ptr<gateway::ApiResponse>;
    using ResponseCallback = std::function<void(const ApiResponsePtr&)>;
    using ErrorCallback = std::function<void(const std::string&)>;

    explicit UserApiGatewayManager(QObject* parent = nullptr) : IApiGatewayManager(parent) {}
    ~UserApiGatewayManager() override = default;

    bool registerResponseCallback(gateway::RequestType requestType, const ResponseCallback& callback) override;
    bool unregisterResponseCallback(gateway::RequestType requestType) override;

    bool createUser(const gateway::UserProperties& userProps);
    bool getUserProperties(const std::string& userId);
    bool updateUserProperties(const gateway::UserProperties& userProps);
    bool getUserSettings(const std::string& userId);
    bool updateUserSettings(const gateway::UserSettings& userSettings);

private:
    std::map<gateway::RequestType, ResponseCallback> m_responseCallbacks;
};
