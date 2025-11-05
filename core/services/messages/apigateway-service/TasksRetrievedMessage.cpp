/**
 * @file TasksRetrievedMessage.cpp
 * @author trung.la
 * @date 11-05-2025
 * @brief This file contains the implementation of the TasksRetrievedMessage class.
 */

#include "TasksRetrievedMessage.h"

namespace {
using namespace apigateway_service::utils::task_management;
}

TasksRetrievedMessage::TasksRetrievedMessage(ExtractTasksStrategyUPtr strategy)
    : Message(MessageId::TasksRetrievedMessage)
    , m_strategy(std::move(strategy))
{
}

TasksRetrievedMessage::~TasksRetrievedMessage() = default;

void TasksRetrievedMessage::setTasks(const Tasks &tasks)
{
	m_tasks = tasks;
}

TasksRetrievedMessage::Tasks TasksRetrievedMessage::getTasks() const
{
	return m_tasks;
}

void TasksRetrievedMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
