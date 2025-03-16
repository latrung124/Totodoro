/*
 * File: WPlaybackInfoExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlaybackInfoExtractStrategy class.
 */

#ifndef WPLAYBACK_INFO_EXTRACT_STRATEGY_H
#define WPLAYBACK_INFO_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WPlaybackInfoMessage;

class WPlaybackInfoExtractStrategy : public ExtractStrategy<WPlaybackInfoMessage>
{
public:
	void extract(const WPlaybackInfoMessage &message) override;
};

#endif // WPLAYBACK_INFO_EXTRACT_STRATEGY_H
