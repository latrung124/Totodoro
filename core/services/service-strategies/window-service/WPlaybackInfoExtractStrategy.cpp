/*
 * File: WPlaybackInfoExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackInfoExtractStrategy class.
 */

#include "core/services/service-strategies/window-service/WPlaybackInfoExtractStrategy.h"

#include <iostream>

#include "core/services/service-messages/window-service/WPlaybackInfoMessage.h"

WPlaybackInfoExtractStrategy::~WPlaybackInfoExtractStrategy()
{
}

void WPlaybackInfoExtractStrategy::execute(const WPlaybackInfoMessage &message)
{
	extract(message);
}

void WPlaybackInfoExtractStrategy::extract(const WPlaybackInfoMessage &message)
{
	std::cout << "Extracting playback info message" << std::endl;
}
