/*
 * File: WPlayAsynMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPlayAsynMessage
 */

#ifndef W_PLAY_ASYNC_MESSAGE_H
#define W_PLAY_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/IStrategy.h"

class WPlayAsyncMessage : public ServiceMessage
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
