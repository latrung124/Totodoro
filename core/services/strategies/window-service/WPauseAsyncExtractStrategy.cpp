/*
 * File: WPauseAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPauseAsyncExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPauseAsyncExtractStrategy.h"

#include <iostream>

#include "core/services/messages/window-service/WPauseAsyncMessage.h"

WPauseAsyncExtractStrategy::~WPauseAsyncExtractStrategy()
{
}

void WPauseAsyncExtractStrategy::execute(const WPauseAsyncMessage &message)
{
	extract(message);
}

void WPauseAsyncExtractStrategy::extract(const WPauseAsyncMessage &message)
{
	std::cout << "Extracting pause async message" << std::endl;
}
