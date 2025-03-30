/*
 * File: WPauseAsyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPauseAsyncMessage
 */

#include "core/services/service-messages/window-service/WPauseAsyncMessage.h"

WPauseAsyncMessage::WPauseAsyncMessage(ExtractWPauseAsyncStrategyUPtr strategy)
    : ServiceMessage(ServiceMessageId::WPauseAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

void WPauseAsyncMessage::extract()
{
	m_strategy->execute(*this);
}
