/**
 * @file TaskGroupUpdatedCompressStrategy.cpp
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the implementation of the TaskGroupUpdatedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskGroupUpdatedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestUpdateTaskGroupAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskGroupUpdatedCompressStrategy::~TaskGroupUpdatedCompressStrategy()
{
}

void TaskGroupUpdatedCompressStrategy::execute(const RequestUpdateTaskGroupAsyncMessage &message)
{
	compress(message);
}

void TaskGroupUpdatedCompressStrategy::compress(const RequestUpdateTaskGroupAsyncMessage &message)
{
	qDebug() << "TaskGroupUpdatedCompressStrategy::compress, updating task group with ID:"
	         << QString::fromStdString(message.getTaskGroup().groupId);
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestUpdateTaskGroup(message.getTaskGroup());
	} else {
		qDebug() << "TaskGroupUpdatedCompressStrategy::compress - Service not found";
	}
}
