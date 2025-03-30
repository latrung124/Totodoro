/*
 * File: WNextAsyncExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WNextAsyncExtractStrategy class.
 */

#ifndef WNEXT_ASYNC_EXTRACT_STRATEGY_H
#define WNEXT_ASYNC_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/IStrategy.h"

class WNextAsyncMessage;

class WNextAsyncExtractStrategy : public IStrategy<WNextAsyncMessage>
{
public:
	~WNextAsyncExtractStrategy();

	void execute(const WNextAsyncMessage &message) override;

private:
	void extract(const WNextAsyncMessage &message);
};

#endif // WNEXT_ASYNC_EXTRACT_STRATEGY_H
