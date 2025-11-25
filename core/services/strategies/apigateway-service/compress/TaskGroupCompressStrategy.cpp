/**
 * @file TaskGroupCompressStrategy.cpp
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the implementation of the TaskGroupCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskGroupCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestCreateTaskGroupAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskGroupCompressStrategy::~TaskGroupCompressStrategy()
{
}

void TaskGroupCompressStrategy::execute(const RequestCreateTaskGroupAsyncMessage &message)
{
	compress(message);
}

void TaskGroupCompressStrategy::compress(const RequestCreateTaskGroupAsyncMessage &message)
{
	qDebug() << "TaskGroupCompressStrategy::compress, creating task group with ID:"
	         << QString::fromStdString(message.getTaskGroup().groupId);
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestCreateTaskGroup(message.getTaskGroup());
	} else {
		qDebug() << "TaskGroupCompressStrategy::compress - Service not found";
	}
}
