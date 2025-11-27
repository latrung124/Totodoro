/**
 * @file TaskGroupsRetrievedCompressStrategy.cpp
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the implementation of the TaskGroupsRetrievedCompressStrategy class.
 */

#include "core/services/strategies/apigateway-service/compress/TaskGroupsRetrievedCompressStrategy.h"

#include <QDebug>

#include <IApiGatewayService.h>

#include "core/services/messages/apigateway-service/RequestGetTaskGroupsAsyncMessage.h"
#include "core/services/ServiceManager.h"

TaskGroupsRetrievedCompressStrategy::~TaskGroupsRetrievedCompressStrategy()
{
}

void TaskGroupsRetrievedCompressStrategy::execute(const RequestGetTaskGroupsAsyncMessage &message)
{
	compress(message);
}

void TaskGroupsRetrievedCompressStrategy::compress(const RequestGetTaskGroupsAsyncMessage &message)
{
	qDebug() << "TaskGroupsRetrievedCompressStrategy::compress, retrieving task groups for user ID:"
	         << QString::fromStdString(message.getUserId());
	auto service = ServiceManager::instance().getService<IApiGatewayService>();
	if (service != nullptr) {
		service->requestGetTaskGroups(message.getUserId());
	} else {
		qDebug() << "TaskGroupsRetrievedCompressStrategy::compress - Service not found";
	}
}
