/*
 * File: WTimelinePropertiesExtractStrategy.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WTimelinePropertiesExtractStrategy class.
 */

#ifndef WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H
#define WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H

#include "core/services/strategies/IStrategy.h"

class WTimelinePropertiesMessage;

class WTimelinePropertiesExtractStrategy : public IStrategy<WTimelinePropertiesMessage>
{
public:
	~WTimelinePropertiesExtractStrategy();

	void execute(const WTimelinePropertiesMessage &message) override;

private:
	void extract(const WTimelinePropertiesMessage &message);
};

#endif // WTIMELINE_PROPERTIES_EXTRACT_STRATEGY_H
