/**
 * @file TasksRetrievedExtractStrategy.cpp
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the implementation of the TasksRetrievedExtractStrategy class.
 */

#include "core/services/strategies/apigateway-service/TasksRetrievedExtractStrategy.h"
#include "core/services/messages/apigateway-service/TasksRetrievedMessage.h"

#include <QDebug>

TasksRetrievedExtractStrategy::~TasksRetrievedExtractStrategy()
{
}

void TasksRetrievedExtractStrategy::execute(const TasksRetrievedMessage &message)
{
	extract(message);
}

void TasksRetrievedExtractStrategy::extract(const TasksRetrievedMessage &message)
{
	qDebug() << "TasksRetrievedExtractStrategy::extract";
	auto tasks = message.getTasks();
	for (const auto &task : tasks) {
		qDebug() << "Task:" << task.taskId.c_str() << "-" << QString::fromStdString(task.name);
		// TODO: Add the logic to handle each retrieved task
	}
}
