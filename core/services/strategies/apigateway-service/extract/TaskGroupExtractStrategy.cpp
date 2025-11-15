/**
 * @file TaskGroupExtractStrategy.cpp
 * @author trung.la
 * @date 11-01-2025
 * @brief Implementation of the TaskGroupExtractStrategy class for extracting task group data.
 */

#include "core/services/strategies/apigateway-service/extract/TaskGroupExtractStrategy.h"

#include <QDebug>

TaskGroupExtractStrategy::~TaskGroupExtractStrategy() = default;

void TaskGroupExtractStrategy::execute(const TaskGroupMessage &message)
{
	extract(message);
}

void TaskGroupExtractStrategy::extract(const TaskGroupMessage &message)
{
	qDebug() << "TaskGroupExtractStrategy::extract";
	// TODO: Extract relevant data from the message
}
