/*
 * File: WTimelinePropertiesMessage.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WTimelinePropertiesMessage class.
 */

#include "WTimelinePropertiesMessage.h"

namespace {

using namespace window_services::media::utils;

} // namespace

WTimelinePropertiesMessage::WTimelinePropertiesMessage()
    : ServiceMessage(ServiceMessageId::WTimelinePropertiesMessage)
{
}

void WTimelinePropertiesMessage::setTimelineProperties(const WTimelineProperties &timelineProperties)
{
	m_timelineProperties = timelineProperties;
}

WTimelineProperties WTimelinePropertiesMessage::getTimelineProperties() const
{
	return m_timelineProperties;
}
