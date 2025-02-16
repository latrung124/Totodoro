/*
* File: IWMediaServiceListener.h
* Author: trung.la
* Date: 02-09-2025
* Description: Interface for media service listener
*/

#ifndef IW_MEDIA_SERVICE_LISTENER_H
#define IW_MEDIA_SERVICE_LISTENER_H

#include <IServiceListener.h>
#include <WMediaServiceUtils.h>

class IWMediaServiceListener : public IServiceListener
{
public:
    using WMediaInfo = window_services::media::utils::WMediaInfo;
    using WPlaybackControls = window_services::media::utils::WPlaybackControls;
    using WPlaybackInfo = window_services::media::utils::WPlaybackInfo;

	IWMediaServiceListener() = default;
	virtual ~IWMediaServiceListener() = default;

    virtual void onMediaInfoChanged(const WMediaInfo &mediaInfo) = 0;
    virtual void onPlaybackControlsChanged(const WPlaybackControls &playbackControls) = 0;
    virtual void onPlaybackStatusChanged(const WPlaybackInfo &playbackInfo) = 0;
};

#endif // IW_MEDIA_SERVICE_LISTENER_H
