/*
 * File: WTimelinePropertiesMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WTimelinePropertiesMessage class.
 */

#ifndef W_TIMELINE_PROPERTIES_MESSAGE_H
#define W_TIMELINE_PROPERTIES_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"
#include <WMediaServiceUtils.h>

class WTimelinePropertiesMessage : public Message
{
public:
	using WTimelineProperties = window_services::media::utils::WTimelineProperties;
	using WTimelinePropertiesExtractStrategyUPtr =
	    std::unique_ptr<IStrategy<WTimelinePropertiesMessage>>;

	WTimelinePropertiesMessage(WTimelinePropertiesExtractStrategyUPtr strategy);
	~WTimelinePropertiesMessage() = default;

	void setTimelineProperties(const WTimelineProperties &timelineProperties);
	WTimelineProperties getTimelineProperties() const;

	void extract() override;

private:
	WTimelineProperties m_timelineProperties;
	WTimelinePropertiesExtractStrategyUPtr m_strategy;
};

#endif // W_TIMELINE_PROPERTIES_MESSAGE_H
