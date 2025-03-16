/*
 * File: WPlaybackControlsExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlaybackControlsExtractStrategy class.
 */

#ifndef WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H
#define WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WPlaybackControlsMessage;

class WPlaybackControlsExtractStrategy : public ExtractStrategy<WPlaybackControlsMessage>
{
public:
	void extract(const WPlaybackControlsMessage &message) override;
};

#endif // WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H
