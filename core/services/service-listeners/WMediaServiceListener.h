/*
 * File: WMediaServiceListener.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for media service listener
 */

#ifndef W_MEDIA_SERVICE_LISTENER_H
#define W_MEDIA_SERVICE_LISTENER_H

#include <IWMediaServiceListener.h>

class WMediaServiceListener : public IWMediaServiceListener
{
public:
	WMediaServiceListener() = default;
	virtual ~WMediaServiceListener() = default;

	void onMediaInfoChanged(const WMediaInfo &mediaInfo) override;
	void onPlaybackControlsChanged(const WPlaybackControls &playbackControls) override;
	void onPlaybackStatusChanged(const WPlaybackInfo &playbackInfo) override;
};

#endif // W_MEDIA_SERVICE_LISTENER_H
