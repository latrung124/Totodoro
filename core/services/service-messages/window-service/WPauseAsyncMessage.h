/*
 * File: WPauseAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This defines class WPauseAsyncMessage
 */

#ifndef W_PAUSE_ASYNC_MESSAGE_H
#define W_PAUSE_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/IStrategy.h"

class WPauseAsyncMessage : public ServiceMessage
{
public:
	using ExtractWPauseAsyncStrategyUPtr = std::unique_ptr<IStrategy<WPauseAsyncMessage>>;

	WPauseAsyncMessage(ExtractWPauseAsyncStrategyUPtr strategy);
	~WPauseAsyncMessage() = default;

	void extract() override;

private:
	ExtractWPauseAsyncStrategyUPtr m_strategy;
};

#endif // W_PAUSE_ASYNC_MESSAGE_H
