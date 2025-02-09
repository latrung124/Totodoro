/*
* File: WPlaybackInfoMessage.h
* Author: trung.la
* Date: 02-09-2025
* Description: Playback info message class
*/

#ifndef W_PLAYBACK_INFO_MESSAGE_H
#define W_PLAYBACK_INFO_MESSAGE_H

#include "core/handlers/service-messages/ServiceMessage.h"
#include "interfaces/window-services/WMediaServiceUtils.h"

class WPlaybackInfoMessage : public ServiceMessage
{
public:
    using WPlaybackInfo = window_services::media::utils::WPlaybackInfo;

    WPlaybackInfoMessage();
    ~WPlaybackInfoMessage() = default;

    void setWPlaybackInfo(const WPlaybackInfo& wPlaybackInfo);
    WPlaybackInfo getWPlaybackInfo() const;

private:
    WPlaybackInfo m_wPlaybackInfo;
};

#endif // W_PLAYBACK_INFO_MESSAGE_H