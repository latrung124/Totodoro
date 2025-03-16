/*
 * File: WTimelinePropertiesExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WTimelinePropertiesExtractStrategy class.
 */

#ifndef WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H
#define WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H

#include "core/services/service-strategies/ExtractStrategy.h"

class WTimelinePropertiesMessage;

class WTimelinePropertiesExtractStrategy : public ExtractStrategy<WTimelinePropertiesMessage>
{
public:
	void extract(const WTimelinePropertiesMessage &message) override;
};

#endif // WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H
