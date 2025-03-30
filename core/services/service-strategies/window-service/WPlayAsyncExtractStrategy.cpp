/*
 * File: WPlayAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlayAsyncExtractStrategy class.
 */

#include "core/services/service-strategies/window-service/WPlayAsyncExtractStrategy.h"

#include <iostream>

#include "core/services/service-messages/window-service/WPlayAsyncMessage.h"

WPlayAsyncExtractStrategy::~WPlayAsyncExtractStrategy()
{
}

void WPlayAsyncExtractStrategy::execute(const WPlayAsyncMessage &message)
{
	extract(message);
}

void WPlayAsyncExtractStrategy::extract(const WPlayAsyncMessage &message)
{
	std::cout << "Extracting play async message" << std::endl;
}
