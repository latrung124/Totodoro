/*
 * File: WNextAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WNextAsyncMessage
 */

#ifndef W_NEXT_ASYNC_MESSAGE_H
#define W_NEXT_ASYNC_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"

class WNextAsyncMessage : public Message
{
public:
	using ExtractWNextAsyncStrategyUPtr = std::unique_ptr<IStrategy<WNextAsyncMessage>>;

	WNextAsyncMessage(ExtractWNextAsyncStrategyUPtr strategy);
	~WNextAsyncMessage() = default;

	void extract() override;

private:
	ExtractWNextAsyncStrategyUPtr m_strategy;
};

#endif // W_NEXT_ASYNC_MESSAGE_H
