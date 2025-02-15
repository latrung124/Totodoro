/*
* File: WPlaybackControlsMessage.h
* Author: trung.la
* Date: 02-09-2025
* Description: Playback controls message class
*/

#ifndef W_PLAYBACK_CONTROLS_MESSAGE_H
#define W_PLAYBACK_CONTROLS_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "interfaces/window-services/WMediaServiceUtils.h"

class WPlaybackControlsMessage : public ServiceMessage
{
public:
    using WPlaybackControls = window_services::media::utils::WPlaybackControls;

    WPlaybackControlsMessage();
    ~WPlaybackControlsMessage() = default;

    void setWPlaybackControls(const WPlaybackControls& wPlaybackControls);
    WPlaybackControls getWPlaybackControls() const;

private:
    WPlaybackControls m_wPlaybackControls;
};

#endif // W_PLAYBACK_CONTROLS_MESSAGE_H