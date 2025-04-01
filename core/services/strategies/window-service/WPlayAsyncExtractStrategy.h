/*
 * File: WPlayAsyncExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlayAsyncExtractStrategy class.
 */

#ifndef WPLAY_ASYNC_EXTRACT_STRATEGY_H
#define WPLAY_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class WPlayAsyncMessage;

class WPlayAsyncExtractStrategy : public IStrategy<WPlayAsyncMessage>
{
public:
	~WPlayAsyncExtractStrategy();

	void execute(const WPlayAsyncMessage &message) override;

private:
	void extract(const WPlayAsyncMessage &message);
};

#endif // WPLAY_ASYNC_EXTRACT_STRATEGY_H
