/**
 * @file TaskDeletedExtractStrategy.cpp
 * @author trung.la
 * @date 11-03-2025
 * @brief This file contains the implementation of the TaskDeletedExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/TaskDeletedExtractStrategy.h"
#include "core/services/messages/apigateway-service/TaskDeletedMessage.h"

#include <QDebug>

TaskDeletedExtractStrategy::~TaskDeletedExtractStrategy()
{
}

void TaskDeletedExtractStrategy::execute(const TaskDeletedMessage &message)
{
	extract(message);
}

void TaskDeletedExtractStrategy::extract(const TaskDeletedMessage &message)
{
	qDebug() << "TaskDeletedExtractStrategy::extract";
	auto taskId = message.getTaskId();
	// TODO: Add the logic to handle the deleted task using the taskId
	qDebug() << "Deleted Task ID:" << QString::fromStdString(taskId);
}
