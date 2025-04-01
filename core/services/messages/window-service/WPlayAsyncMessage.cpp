/*
 * File: WPlayAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPlayAsyncMessage
 */

#include "core/services/messages/window-service/WPlayAsyncMessage.h"

WPlayAsyncMessage::WPlayAsyncMessage(ExtractWPlayAsyncStrategyUPtr strategy)
    : Message(MessageId::WPlayAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

void WPlayAsyncMessage::extract()
{
	m_strategy->execute(*this);
}
