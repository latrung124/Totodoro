/**
 * @file TaskMessage.cpp
 * @author trung.la
 * @date 10-31-2025
 * @brief Implementation of the TaskMessage class for managing task-related messages.
 */

#include "TaskMessage.h"

namespace {
using namespace apigateway_service::utils::task_management;
}

TaskMessage::TaskMessage(ExtractTaskStrategyUPtr strategy)
    : Message(MessageId::TaskMessage)
    , m_strategy(std::move(strategy))
{
}

TaskMessage::~TaskMessage() = default;

void TaskMessage::setTask(const Task &task)
{
	m_task = task;
}

TaskMessage::Task TaskMessage::getTask() const
{
	return m_task;
}

void TaskMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
