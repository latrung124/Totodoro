/*
 * File: WTimelinePropertiesMessage.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WTimelinePropertiesMessage class.
 */

#ifndef W_TIMELINE_PROPERTIES_MESSAGE_H
#define W_TIMELINE_PROPERTIES_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include <WMediaServiceUtils.h>

class WTimelinePropertiesMessage : public ServiceMessage
{
public:
	using WTimelineProperties = window_services::media::utils::WTimelineProperties;

	WTimelinePropertiesMessage();
	~WTimelinePropertiesMessage() = default;

	void setTimelineProperties(const WTimelineProperties &timelineProperties);
	WTimelineProperties getTimelineProperties() const;

private:
	WTimelineProperties m_timelineProperties;
};

#endif // W_TIMELINE_PROPERTIES_MESSAGE_H
