/**
 * @file TaskGroupMessage.cpp
 * @author trung.la
 * @date 11-01-2025
 * @brief Implementation of the TaskGroupMessage class for managing task group-related messages.
 */

#include "TaskGroupMessage.h"

namespace {
using namespace apigateway_service::utils::task_management;
}

TaskGroupMessage::TaskGroupMessage(ExtractTaskGroupStrategyUPtr strategy)
    : Message(MessageId::TaskGroupMessage)
    , m_strategy(std::move(strategy))
{
}

TaskGroupMessage::~TaskGroupMessage() = default;

void TaskGroupMessage::setTaskGroup(const TaskGroup &taskGroup)
{
	m_taskGroup = taskGroup;
}

TaskGroupMessage::TaskGroup TaskGroupMessage::getTaskGroup() const
{
	return m_taskGroup;
}

void TaskGroupMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
