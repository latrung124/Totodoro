/*
File: WPlaybackInfoMessage.cpp
Author: trung.la
Date: 02-09-2025
Description: Implementation for Window Media Playback Info Message
*/

#include "WPlaybackInfoMessage.h"

namespace {

using namespace window_services::media::utils;

}

WPlaybackInfoMessage::WPlaybackInfoMessage(ExtractWPlaybackInfoStrategyUPtr strategy)
    : ServiceMessage(ServiceMessageId::WPlaybackInfoMessage)
    , m_strategy(std::move(strategy))
{
}

void WPlaybackInfoMessage::setWPlaybackInfo(const WPlaybackInfo &wPlaybackInfo)
{
	m_wPlaybackInfo = wPlaybackInfo;
}

WPlaybackInfo WPlaybackInfoMessage::getWPlaybackInfo() const
{
	return m_wPlaybackInfo;
}

void WPlaybackInfoMessage::extract()
{
	m_strategy->extract(*this);
}
