/**
 * @file RequestDeleteTaskGroupAsyncMessage.cpp
 * @author trung.la
 * @date 11-26-2025
 * @brief This file contains the implementation of the RequestDeleteTaskGroupAsyncMessage class.
 */

#include "core/services/messages/apigateway-service/RequestDeleteTaskGroupAsyncMessage.h"

RequestDeleteTaskGroupAsyncMessage::RequestDeleteTaskGroupAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestDeleteTaskGroupAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestDeleteTaskGroupAsyncMessage::~RequestDeleteTaskGroupAsyncMessage() = default;

void RequestDeleteTaskGroupAsyncMessage::setTaskGroupId(const std::string &taskGroupId)
{
	m_taskGroupId = taskGroupId;
}

std::string RequestDeleteTaskGroupAsyncMessage::getTaskGroupId() const
{
	return m_taskGroupId;
}

void RequestDeleteTaskGroupAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
