/*
 * File: WPlayAsyncExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlayAsyncExtractStrategy class.
 */

#ifndef WPLAY_ASYNC_EXTRACT_STRATEGY_H
#define WPLAY_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WPlayAsyncMessage;

class WPlayAsyncExtractStrategy : public ExtractStrategy<WPlayAsyncMessage>
{
public:
	void extract(const WPlayAsyncMessage &message) override;
};

#endif // WPLAY_ASYNC_EXTRACT_STRATEGY_H
