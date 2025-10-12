/**
 * @file Gateway.h
 * @author trung.la
 * @date 09-07-2025
 * @brief Declaration of the Gateway to communicate with Backend services via RestApi.
 */

#pragma once

#include <memory>
#include <map>

#include "common/CommonDefine.h"

class IApiGatewayManager;

namespace gateway {

class PomodoroOpenApiController;

class Gateway
{
public:
    Gateway() = default;
    ~Gateway() = default;

    bool start();
    bool stop();

    std::weak_ptr<IApiGatewayManager> getApiGatewayManager(gateway::RouteType routeType) const;

private:
    bool initialize();

    std::shared_ptr<PomodoroOpenApiController> mPomodoroController;
    std::map<gateway::RouteType, std::shared_ptr<IApiGatewayManager>> mApiGatewayManagers;
};

} // namespace gateway
