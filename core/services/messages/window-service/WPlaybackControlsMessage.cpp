/*
 * File: WPlaybackControlsMessage.cpp
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Implementation for Window Media Playback Controls Message
 */

#include "WPlaybackControlsMessage.h"

namespace {

using namespace window_services::media::utils;

}

WPlaybackControlsMessage::WPlaybackControlsMessage(ExtractWPlaybackControlsStrategyUPtr strategy)
    : Message(MessageId::WPlaybackControlsMessage)
    , m_strategy(std::move(strategy))
{
}

void WPlaybackControlsMessage::setWPlaybackControls(const WPlaybackControls &wPlaybackControls)
{
	m_wPlaybackControls = wPlaybackControls;
}

WPlaybackControls WPlaybackControlsMessage::getWPlaybackControls() const
{
	return m_wPlaybackControls;
}

void WPlaybackControlsMessage::extract()
{
	m_strategy->execute(*this);
}
