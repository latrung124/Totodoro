/*
 * File: WPlaybackControlsExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackControlsExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPlaybackControlsExtractStrategy.h"

#include <iostream>

#include "core/services/messages/window-service/WPlaybackControlsMessage.h"

WPlaybackControlsExtractStrategy::~WPlaybackControlsExtractStrategy()
{
}

void WPlaybackControlsExtractStrategy::execute(const WPlaybackControlsMessage &message)
{
	extract(message);
}

void WPlaybackControlsExtractStrategy::extract(const WPlaybackControlsMessage &message)
{
	std::cout << "Extracting playback controls!" << std::endl;
}
