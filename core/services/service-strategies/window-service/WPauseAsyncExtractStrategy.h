/*
 * File: WPauseAsyncExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPauseAsyncExtractStrategy class.
 */

#ifndef WPAUSE_ASYNC_EXTRACT_STRATEGY_H
#define WPAUSE_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WPauseAsyncMessage;

class WPauseAsyncExtractStrategy : public ExtractStrategy<WPauseAsyncMessage>
{
public:
	void extract(const WPauseAsyncMessage &message) override;
};

#endif // WPAUSE_ASYNC_EXTRACT_STRATEGY_H
