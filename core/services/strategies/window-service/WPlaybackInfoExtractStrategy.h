/*
 * File: WPlaybackInfoExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlaybackInfoExtractStrategy class.
 */

#ifndef WPLAYBACK_INFO_EXTRACT_STRATEGY_H
#define WPLAYBACK_INFO_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class WPlaybackInfoMessage;

class WPlaybackInfoExtractStrategy : public IStrategy<WPlaybackInfoMessage>
{
public:
	~WPlaybackInfoExtractStrategy();

	void execute(const WPlaybackInfoMessage &message) override;

private:
	void extract(const WPlaybackInfoMessage &message);
};

#endif // WPLAYBACK_INFO_EXTRACT_STRATEGY_H
