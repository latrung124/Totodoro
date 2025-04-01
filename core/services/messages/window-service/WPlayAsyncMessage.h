/*
 * File: WPlayAsynMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPlayAsynMessage
 */

#ifndef W_PLAY_ASYNC_MESSAGE_H
#define W_PLAY_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

class WPlayAsyncMessage : public Message
{
public:
	using ExtractWPlayAsyncStrategyUPtr = std::unique_ptr<IStrategy<WPlayAsyncMessage>>;

	WPlayAsyncMessage(ExtractWPlayAsyncStrategyUPtr strategy);
	~WPlayAsyncMessage() = default;

	void extract() override;

private:
	ExtractWPlayAsyncStrategyUPtr m_strategy;
};

#endif // W_PLAY_ASYNC_MESSAGE_H
