/**
 * @file Gateway.cpp
 * @author trung.la
 * @date 09-07-2025
 * @brief Implementation file for Gateway class that communicates with Backend services via RestApi.
 */

#include "Gateway.h"

#include <QDebug>

#include "CommonDefine.h"
#include "PomodoroOpenApiController.h"
#include "AsyncRequestProcessor.h"
#include "ApiClientFactory.h"
#include "ApiGatewayManagerFactory.h"

namespace gateway
{

bool Gateway::initialize()
{
    auto requestProcessor = std::make_shared<AsyncRequestProcessor>();
    if (requestProcessor == nullptr) {
        qCritical() << "Failed to create AsyncRequestProcessor";
        return false;
    }

    auto apiClientFactory = std::make_shared<ApiClientFactory>();
    if (apiClientFactory == nullptr) {
        qCritical() << "Failed to create ApiClientFactory";
        return false;
    }

    mPomodoroController = std::make_shared<PomodoroOpenApiController>(
        requestProcessor,
        apiClientFactory,
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

} // namespace gateway
