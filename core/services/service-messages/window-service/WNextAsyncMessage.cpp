/*
 * File: WNextAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WNextAsyncMessage
 */

#include "core/services/service-messages/window-service/WNextAsyncMessage.h"

WNextAsyncMessage::WNextAsyncMessage(ExtractWNextAsyncStrategyUPtr strategy)
    : ServiceMessage(ServiceMessageId::WNextAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

void WNextAsyncMessage::extract()
{
	m_strategy->extract(*this);
}
