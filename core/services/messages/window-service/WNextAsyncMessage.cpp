/*
 * File: WNextAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WNextAsyncMessage
 */

#include "core/services/messages/window-service/WNextAsyncMessage.h"

WNextAsyncMessage::WNextAsyncMessage(ExtractWNextAsyncStrategyUPtr strategy)
    : Message(MessageId::WNextAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

void WNextAsyncMessage::execute()
{
	m_strategy->execute(*this);
}
