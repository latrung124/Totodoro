/**
 * @file RequestUserSettingsAsyncMessage.cpp
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the implementation of the RequestUserSettingsAsyncMessage class.
 */

#include "core/services/messages/apigateway-service/RequestUserSettingsAsyncMessage.h"

RequestUserSettingsAsyncMessage::RequestUserSettingsAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestUserSettingsAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestUserSettingsAsyncMessage::~RequestUserSettingsAsyncMessage() = default;

std::string RequestUserSettingsAsyncMessage::getUserId() const
{
	return m_userId;
}

void RequestUserSettingsAsyncMessage::setUserId(const std::string &userId)
{
	m_userId = userId;
}

void RequestUserSettingsAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
