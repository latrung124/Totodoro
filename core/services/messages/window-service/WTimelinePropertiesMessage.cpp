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

WTimelinePropertiesMessage::WTimelinePropertiesMessage(
    WTimelinePropertiesExtractStrategyUPtr strategy)
    : Message(MessageId::WTimelinePropertiesMessage)
    , m_strategy(std::move(strategy))
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

void WTimelinePropertiesMessage::execute()
{
	m_strategy->execute(*this);
}
