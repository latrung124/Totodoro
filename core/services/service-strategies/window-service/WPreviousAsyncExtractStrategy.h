/*
 * File: WPreviousAsyncExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPreviousAsyncExtractStrategy class.
 */

#ifndef WPREVIOUS_ASYNC_EXTRACT_STRATEGY_H
#define WPREVIOUS_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/IStrategy.h"

class WPreviousAsyncMessage;

class WPreviousAsyncExtractStrategy : public IStrategy<WPreviousAsyncMessage>
{
public:
	~WPreviousAsyncExtractStrategy();

	void execute(const WPreviousAsyncMessage &message) override;

private:
	void extract(const WPreviousAsyncMessage &message);
};

#endif // WPREVIOUS_ASYNC_EXTRACT_STRATEGY_H
