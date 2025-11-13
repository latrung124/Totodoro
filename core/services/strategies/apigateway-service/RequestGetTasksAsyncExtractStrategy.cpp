/**
 * @file RequestGetTasksAsyncExtractStrategy.cpp
 * @author trung.la
 * @date 11-13-2025
 * @brief This file contains the implementation of the RequestGetTasksAsyncExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/RequestGetTasksAsyncExtractStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestGetTasksAsyncMessage.h"
#include "core/services/ServiceManager.h"

RequestGetTasksAsyncExtractStrategy::~RequestGetTasksAsyncExtractStrategy()
{
}

void RequestGetTasksAsyncExtractStrategy::execute(const RequestGetTasksAsyncMessage &message)
{
	extract(message);
}

void RequestGetTasksAsyncExtractStrategy::extract(const RequestGetTasksAsyncMessage &message)
{
	qDebug() << "RequestGetTasksAsyncExtractStrategy::extract";
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestGetTasks(message.getUserId(), message.getTaskGroupId());
	} else {
		qDebug() << "RequestGetTasksAsyncExtractStrategy::extract - Service not found";
	}
}
