/**
 * @file TaskGroupDeletedExtractStrategy.cpp
 * @author trung.la
 * @date 11-06-2025
 * @brief This file contains the implementation of the TaskGroupDeletedExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/extract/TaskGroupDeletedExtractStrategy.h"
#include "core/services/messages/apigateway-service/TaskGroupDeletedMessage.h"

#include <QDebug>

TaskGroupDeletedExtractStrategy::~TaskGroupDeletedExtractStrategy()
{
}

void TaskGroupDeletedExtractStrategy::execute(const TaskGroupDeletedMessage &message)
{
	extract(message);
}

void TaskGroupDeletedExtractStrategy::extract(const TaskGroupDeletedMessage &message)
{
	qDebug() << "TaskGroupDeletedExtractStrategy::extract";
	auto taskGroupId = message.getGroupId();
	// TODO: Add the logic to handle the deleted task group using the taskGroupId
	qDebug() << "Extracted Task Group ID:" << taskGroupId;
}
