/**
 * @file RequestUserInformationAsyncMessage.cpp
 * @author trung.la
 * @date 12-01-2025
 * @brief This file contains the implementation of the RequestUserInformationAsyncMessage class.
 */

#include "core/services/messages/apigateway-service/RequestUserInformationAsyncMessage.h"

RequestUserInformationAsyncMessage::RequestUserInformationAsyncMessage(CompressStrategyUPtr strategy)
    : Message(MessageId::RequestUserInformationAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

RequestUserInformationAsyncMessage::~RequestUserInformationAsyncMessage() = default;

std::string RequestUserInformationAsyncMessage::getEmail() const
{
	return m_email;
}

void RequestUserInformationAsyncMessage::setEmail(const std::string &email)
{
	m_email = email;
}

void RequestUserInformationAsyncMessage::execute()
{
	if (m_strategy) {
		m_strategy->execute(*this);
	}
}
