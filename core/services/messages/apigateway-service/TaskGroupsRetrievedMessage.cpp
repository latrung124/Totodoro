/**
 * @file TaskGroupsRetrievedMessage.cpp
 * @author trung.la
 * @date 11-08-2025
 * @brief This file contains the implementation of the TaskGroupsRetrievedMessage class.
 */

#include "TaskGroupsRetrievedMessage.h"

namespace {
using namespace apigateway_service::utils::task_management;
}

TaskGroupsRetrievedMessage::TaskGroupsRetrievedMessage(ExtractTaskGroupsStrategyUPtr strategy)
    : Message(MessageId::TaskGroupsRetrievedMessage)
    , m_strategy(std::move(strategy))
{
}

TaskGroupsRetrievedMessage::~TaskGroupsRetrievedMessage() = default;

void TaskGroupsRetrievedMessage::setTaskGroups(const TaskGroups &taskGroups)
{
	m_taskGroups = taskGroups;
}

TaskGroupsRetrievedMessage::TaskGroups TaskGroupsRetrievedMessage::getTaskGroups() const
{
	return m_taskGroups;
}

void TaskGroupsRetrievedMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
