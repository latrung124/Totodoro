/*
 * File: WPlaybackControlsExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlaybackControlsExtractStrategy class.
 */

#ifndef WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H
#define WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class WPlaybackControlsMessage;

class WPlaybackControlsExtractStrategy : public IStrategy<WPlaybackControlsMessage>
{
public:
	~WPlaybackControlsExtractStrategy();

	void execute(const WPlaybackControlsMessage &message) override;

private:
	void extract(const WPlaybackControlsMessage &message);
};

#endif // WPLAYBACK_CONTROLS_EXTRACT_STRATEGY_H
