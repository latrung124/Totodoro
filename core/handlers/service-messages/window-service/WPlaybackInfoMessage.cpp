/*
File: WPlaybackInfoMessage.cpp
Author: trung.la
Date: 02-09-2025
Description: Implementation for Window Media Playback Info Message
*/

#include "WPlaybackInfoMessage.h"

namespace
{
    using namespace window_services::media::utils;
}

WPlaybackInfoMessage::WPlaybackInfoMessage()
    : ServiceMessage(ServiceMessageId::WPlaybackInfoMessage)
{
}

void WPlaybackInfoMessage::setWPlaybackInfo(const WPlaybackInfo& wPlaybackInfo)
{
    m_wPlaybackInfo = wPlaybackInfo;
}

WPlaybackInfo WPlaybackInfoMessage::getWPlaybackInfo() const
{
    return m_wPlaybackInfo;
}