/*
 * File: WPauseAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPauseAsyncMessage
 */

#ifndef W_PAUSE_ASYNC_MESSAGE_H
#define W_PAUSE_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

class WPauseAsyncMessage : public Message
{
public:
	using ExtractWPauseAsyncStrategyUPtr = std::unique_ptr<IStrategy<WPauseAsyncMessage>>;

	WPauseAsyncMessage(ExtractWPauseAsyncStrategyUPtr strategy);
	~WPauseAsyncMessage() = default;

	void execute() override;

private:
	ExtractWPauseAsyncStrategyUPtr m_strategy;
};

#endif // W_PAUSE_ASYNC_MESSAGE_H
