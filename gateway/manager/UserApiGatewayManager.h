/**
 * @file UserApiGatewayManager.h
 * @author trung.la
 * @date 09-22-2025
 * @brief This file contains the declaration of the UserApiGatewayManager class.
 */

#pragma once

#include <string>
#include <memory>
#include <functional>

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

    bool onCreateUser(const gateway::UserProperties& userProps,
                      const ResponseCallback& onSuccess,
                      const ErrorCallback& onError);

    bool onGetUser(const gateway::UserProperties& userProps,
                   const ResponseCallback& onSuccess,
                   const ErrorCallback& onError);
    
    bool onUpdateUser(const gateway::UserProperties& userProps,
                      const ResponseCallback& onSuccess,
                      const ErrorCallback& onError);

    bool onGetUserSettings(const std::string& userId,
                           const ResponseCallback& onSuccess,
                           const ErrorCallback& onError);

    bool onUpdateUserSettings(const gateway::UserSettings& settings,
                              const ResponseCallback& onSuccess,
                              const ErrorCallback& onError);
};