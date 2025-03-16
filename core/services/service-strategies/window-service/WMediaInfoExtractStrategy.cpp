/*
 * File: WMediaInfoExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WMediaInfoExtractStrategy class.
 */

#include "core/services/service-strategies/window-service/WMediaInfoExtractStrategy.h"

#include <iostream>

#include "core/services/service-messages/window-service/WMediaInfoMessage.h"

void WMediaInfoExtractStrategy::extract(const WMediaInfoMessage &message)
{
	std::cout << "Extracting media info!" << std::endl;
}
