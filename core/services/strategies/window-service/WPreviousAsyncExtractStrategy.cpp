/*
 * File:  WPreviousAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPreviousAsyncExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPreviousAsyncExtractStrategy.h"

#include <iostream>

#include "core/services/messages/window-service/WPreviousAsyncMessage.h"

WPreviousAsyncExtractStrategy::~WPreviousAsyncExtractStrategy()
{
}

void WPreviousAsyncExtractStrategy::execute(const WPreviousAsyncMessage &message)
{
	extract(message);
}

void WPreviousAsyncExtractStrategy::extract(const WPreviousAsyncMessage &message)
{
	std::cout << "Extracting previous async message" << std::endl;
}
