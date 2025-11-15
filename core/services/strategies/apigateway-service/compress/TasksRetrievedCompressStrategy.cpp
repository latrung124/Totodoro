/**
 * @file TasksRetrievedCompressStrategy.cpp
 * @author trung.la
 * @date 11-13-2025
 * @brief This file contains the implementation of the TasksRetrievedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TasksRetrievedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestGetTasksAsyncMessage.h"
#include "core/services/ServiceManager.h"

TasksRetrievedCompressStrategy::~TasksRetrievedCompressStrategy()
{
}

void TasksRetrievedCompressStrategy::execute(const RequestGetTasksAsyncMessage &message)
{
	extract(message);
}

void TasksRetrievedCompressStrategy::extract(const RequestGetTasksAsyncMessage &message)
{
	qDebug() << "TasksRetrievedCompressStrategy::extract";
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestGetTasks(message.getUserId(), message.getTaskGroupId());
	} else {
		qDebug() << "TasksRetrievedCompressStrategy::extract - Service not found";
	}
}
