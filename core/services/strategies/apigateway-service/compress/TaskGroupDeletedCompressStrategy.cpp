/**
 * @file TaskGroupDeletedCompressStrategy.cpp
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the implementation of the TaskGroupDeletedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskGroupDeletedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestDeleteTaskGroupAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskGroupDeletedCompressStrategy::~TaskGroupDeletedCompressStrategy()
{
}

void TaskGroupDeletedCompressStrategy::execute(const RequestDeleteTaskGroupAsyncMessage &message)
{
	compress(message);
}

void TaskGroupDeletedCompressStrategy::compress(const RequestDeleteTaskGroupAsyncMessage &message)
{
	qDebug() << "TaskGroupDeletedCompressStrategy::compress, deleting task group with ID:"
	         << QString::fromStdString(message.getTaskGroupId());
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestDeleteTaskGroup(message.getTaskGroupId());
	} else {
		qDebug() << "TaskGroupDeletedCompressStrategy::compress - Service not found";
	}
}
