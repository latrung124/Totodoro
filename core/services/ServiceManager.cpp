/*
 * File: ServiceManager.cpp
 * Author: trung.la
 * Date: 02-11-2025
 * Description: This file contains the implementation of the ServiceManager class.
 */

#include "core/services/ServiceManager.h"

#include "core/services/listeners/ApiGatewayServiceListener.h"
#include "core/services/listeners/WMediaServiceListener.h"

ServiceManager &ServiceManager::instance()
{
	static ServiceManager serviceManager;
	return serviceManager;
}

ServiceManager::~ServiceManager()
{
	m_services.clear();
}

void ServiceManager::startAllRegisteredServices()
{
	for (const auto &[_, service] : m_services) {
		if (service) {
			qDebug() << "Starting service";
			service->start();
		} else {
			qDebug() << "Service is null";
		}
	}
}

void ServiceManager::registerAllServiceListeners()
{
	auto mediaService = getService<IWMediaService>();
	if (mediaService != nullptr) {
		mediaService->registerListener(new WMediaServiceListener());
	} else {
		qDebug() << "Service is null";
	}

	auto apiGatewayService = getService<IApiGatewayService>();
	if (apiGatewayService != nullptr) {
		apiGatewayService->registerListener(new ApiGatewayServiceListener());
	} else {
		qDebug() << "ApiGatewayService is null";
	}
}
