/*
 * File: WNextAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WNextAsyncExtractStrategy class.
 */

#include "core/services/strategies/window-service/WNextAsyncExtractStrategy.h"

#include <iostream>

#include "core/services/messages/window-service/WNextAsyncMessage.h"

WNextAsyncExtractStrategy::~WNextAsyncExtractStrategy()
{
}

void WNextAsyncExtractStrategy::execute(const WNextAsyncMessage &message)
{
	extract(message);
}

void WNextAsyncExtractStrategy::extract(const WNextAsyncMessage &message)
{
	std::cout << "Extracting next async message" << std::endl;
}
