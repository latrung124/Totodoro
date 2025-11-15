/**
 * @file TaskExtractStrategy.cpp
 * @author trung.la
 * @date 10-31-2025
 * @brief Implementation of the TaskExtractStrategy class for extracting task data.
 */

#include "core/services/strategies/apigateway-service/extract/TaskExtractStrategy.h"

#include <QDebug>

TaskExtractStrategy::~TaskExtractStrategy() = default;

void TaskExtractStrategy::execute(const TaskMessage &message)
{
	extract(message);
}

void TaskExtractStrategy::extract(const TaskMessage &message)
{
	qDebug() << "TaskExtractStrategy::extract";
	// TODO: Implementation for extracting task data from the message
}
