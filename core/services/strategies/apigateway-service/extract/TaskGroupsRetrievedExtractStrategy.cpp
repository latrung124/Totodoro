/**
 * @file TaskGroupsRetrievedExtractStrategy.cpp
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the implementation of the TaskGroupsRetrievedExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/extract/TaskGroupsRetrievedExtractStrategy.h"
#include "core/services/messages/apigateway-service/TaskGroupsRetrievedMessage.h"

#include <QDebug>

TaskGroupsRetrievedExtractStrategy::~TaskGroupsRetrievedExtractStrategy()
{
}

void TaskGroupsRetrievedExtractStrategy::execute(const TaskGroupsRetrievedMessage &message)
{
	extract(message);
}

void TaskGroupsRetrievedExtractStrategy::extract(const TaskGroupsRetrievedMessage &message)
{
	qDebug() << "TaskGroupsRetrievedExtractStrategy::extract";
	auto taskGroups = message.getTaskGroups();
	for (const auto &taskGroup : taskGroups) {
		qDebug() << "Task Group:" << taskGroup.groupId.c_str() << "-"
		         << QString::fromStdString(taskGroup.name);
		// TODO: Add the logic to handle each retrieved task group
	}
}
