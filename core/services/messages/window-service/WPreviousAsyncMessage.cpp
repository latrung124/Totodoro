/*
 * File: WPreviousAyncMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WPreviousAsyncMessage class.
 */

#include "core/services/messages/window-service/WPreviousAsyncMessage.h"

WPreviousAsyncMessage::WPreviousAsyncMessage(ExtractWPreviousAsyncStrategyUPtr strategy)
    : Message(MessageId::WPreviousAsyncMessage)
    , m_strategy(std::move(strategy))
{
}

void WPreviousAsyncMessage::extract()
{
	m_strategy->execute(*this);
}
