/**
 * @file TaskDeletedCompressStrategy.cpp
 * @author trung.la
 * @date 11-23-2025
 * @brief This file contains the implementation of the TaskDeletedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskDeletedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestDeleteTaskAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskDeletedCompressStrategy::~TaskDeletedCompressStrategy()
{
}

void TaskDeletedCompressStrategy::execute(const RequestDeleteTaskAsyncMessage &message)
{
	compress(message);
}

void TaskDeletedCompressStrategy::compress(const RequestDeleteTaskAsyncMessage &message)
{
	qDebug() << "TaskDeletedCompressStrategy::compress, deleting task with ID:"
	         << QString::fromStdString(message.getTaskId());
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestDeleteTask(message.getTaskId());
	} else {
		qDebug() << "TaskDeletedCompressStrategy::compress - Service not found";
	}
}
