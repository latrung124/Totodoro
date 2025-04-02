/*
 * File: WPreviousAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the definition of the WPreviousAsyncMessage class.
 */

#ifndef WPREVIOUS_ASYNC_MESSAGE_H
#define WPREVIOUS_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

class WPreviousAsyncMessage : public Message
{
public:
	using ExtractWPreviousAsyncStrategyUPtr = std::unique_ptr<IStrategy<WPreviousAsyncMessage>>;

	WPreviousAsyncMessage(ExtractWPreviousAsyncStrategyUPtr strategy);
	~WPreviousAsyncMessage() = default;

	void execute() override;

private:
	ExtractWPreviousAsyncStrategyUPtr m_strategy;
};

#endif // WPREVIOUS_ASYNC_MESSAGE_H
