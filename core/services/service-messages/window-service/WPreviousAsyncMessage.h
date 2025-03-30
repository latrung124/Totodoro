/*
 * File: WPreviousAsyncMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the definition of the WPreviousAsyncMessage class.
 */

#ifndef WPREVIOUS_ASYNC_MESSAGE_H
#define WPREVIOUS_ASYNC_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/IStrategy.h"

class WPreviousAsyncMessage : public ServiceMessage
{
public:
	using ExtractWPreviousAsyncStrategyUPtr = std::unique_ptr<IStrategy<WPreviousAsyncMessage>>;

	WPreviousAsyncMessage(ExtractWPreviousAsyncStrategyUPtr strategy);
	~WPreviousAsyncMessage() = default;

	void extract() override;

private:
	ExtractWPreviousAsyncStrategyUPtr m_strategy;
};

#endif // WPREVIOUS_ASYNC_MESSAGE_H
