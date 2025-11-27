/**
 * @file RequestGetTaskGroupsAsyncMessage.cpp
 * @author trung.la
 * @date 11-27-2025
 * @brief This file contains the implementation of the RequestGetTaskGroupsAsyncMessage class.
 */

#include "RequestGetTaskGroupsAsyncMessage.h"

RequestGetTaskGroupsAsyncMessage::RequestGetTaskGroupsAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestGetTaskGroupsAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestGetTaskGroupsAsyncMessage::~RequestGetTaskGroupsAsyncMessage() = default;

void RequestGetTaskGroupsAsyncMessage::setUserId(const std::string &userId)
{
	m_userId = userId;
}

std::string RequestGetTaskGroupsAsyncMessage::getUserId() const
{
	return m_userId;
}

void RequestGetTaskGroupsAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
