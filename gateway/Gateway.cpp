/**
 * @file Gateway.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for Gateway class that communicates with Backend services via RestApi.
 */

#include "Gateway.h"

#include <QDebug>

#include "common/CommonDefine.h"
#include "controller/PomodoroOpenApiController.h"
#include "processor/AsyncRequestProcessor.h"
#include "factory/ApiGatewayManagerFactory.h"

namespace gateway
{

bool Gateway::initialize()
{
    auto requestProcessor = std::make_shared<AsyncRequestProcessor>();
    if (requestProcessor == nullptr) {
        qCritical() << "Failed to create AsyncRequestProcessor";
        return false;
    }

    mPomodoroController = std::make_shared<PomodoroOpenApiController>(
        requestProcessor,
        kBaseUrl.data()
    );

    mApiGatewayManagers[gateway::RouteType::Pomodoro] = ApiGatewayManagerFactory::createManager(gateway::RouteType::Pomodoro);
    mApiGatewayManagers[gateway::RouteType::TaskManagement] = ApiGatewayManagerFactory::createManager(gateway::RouteType::TaskManagement);
    mApiGatewayManagers[gateway::RouteType::User] = ApiGatewayManagerFactory::createManager(gateway::RouteType::User);

    return true;
}

bool Gateway::start()
{
	if (!initialize()) {
		qCritical() << "Failed to initialize the Gateway API!";
		return false;
	} else {
		qDebug() << "Initialize Gateway API successfully!";
	}

	return true;
}

bool Gateway::stop()
{
    return true;
}

std::weak_ptr<IApiGatewayManager> Gateway::getApiGatewayManager(gateway::RouteType routeType) const
{
    auto it = mApiGatewayManagers.find(routeType);
    if (it != mApiGatewayManagers.end()) {
        return it->second;
    }

    return std::weak_ptr<IApiGatewayManager>();
}

} // namespace gateway
