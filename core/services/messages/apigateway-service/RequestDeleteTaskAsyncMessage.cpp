/**
 * @file RequestDeleteTaskAsyncMessage.cpp
 * @author trung.la
 * @date 11-23-2025
 * @brief This file contains the implementation of the RequestDeleteTaskAsyncMessage class.
 */

#include "RequestDeleteTaskAsyncMessage.h"

RequestDeleteTaskAsyncMessage::RequestDeleteTaskAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestDeleteTaskAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestDeleteTaskAsyncMessage::~RequestDeleteTaskAsyncMessage() = default;

void RequestDeleteTaskAsyncMessage::setTaskId(const std::string &taskId)
{
	m_taskId = taskId;
}

std::string RequestDeleteTaskAsyncMessage::getTaskId() const
{
	return m_taskId;
}

void RequestDeleteTaskAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
