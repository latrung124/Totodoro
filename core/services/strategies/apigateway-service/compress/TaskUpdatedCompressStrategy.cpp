/**
 * @file TaskUpdatedCompressStrategy.cpp
 * @author trung.la
 * @date 11-24-2025
 * @brief This file contains the implementation of the TaskUpdatedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskUpdatedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestUpdateTaskAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskUpdatedCompressStrategy::~TaskUpdatedCompressStrategy()
{
}

void TaskUpdatedCompressStrategy::execute(const RequestUpdateTaskAsyncMessage &message)
{
	compress(message);
}

void TaskUpdatedCompressStrategy::compress(const RequestUpdateTaskAsyncMessage &message)
{
	qDebug() << "TaskUpdatedCompressStrategy::compress, updating task with ID:"
	         << QString::fromStdString(message.getTask().taskId);
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestUpdateTask(message.getTask());
	} else {
		qDebug() << "TaskUpdatedCompressStrategy::compress - Service not found";
	}
}
