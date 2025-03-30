/*
 * File: WTimelinePropertiesExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WTimelinePropertiesExtractStrategy class.
 */

#include "core/services/service-strategies/window-service/WTimelinePropertiesExtractStrategy.h"

#include <iostream>

#include "core/services/service-messages/window-service/WTimelinePropertiesMessage.h"

WTimelinePropertiesExtractStrategy::~WTimelinePropertiesExtractStrategy()
{
}

void WTimelinePropertiesExtractStrategy::execute(const WTimelinePropertiesMessage &message)
{
	extract(message);
}

void WTimelinePropertiesExtractStrategy::extract(const WTimelinePropertiesMessage &message)
{
	std::cout << "Extracting timeline properties message" << std::endl;
}
