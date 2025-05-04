/*
 * File: WindowMediaService.h
 * Author: trung.la
 * Date: 02-07-2025
 * Description: This file contains the declaration of the WindowMediaService class
 */

#ifndef WINDOW_MEDIA_SERVICE_H
#define WINDOW_MEDIA_SERVICE_H

#include <IWMediaService.h>
#include <WMediaServiceUtils.h>

#include <memory>

class WindowSystemMedia;

class WMEDIA_SERVICE_API WindowMediaService : public IWMediaService
{
public:
	using WMediaInfo = window_services::media::utils::WMediaInfo;
	using WPlaybackInfo = window_services::media::utils::WPlaybackInfo;
	using WTimelineProperties = window_services::media::utils::WTimelineProperties;
	using WindowSystemMediaUPtr = std::unique_ptr<WindowSystemMedia>;

	WindowMediaService();
	~WindowMediaService() override;

	WindowMediaService(const WindowMediaService &) = delete;
	WindowMediaService &operator=(const WindowMediaService &) = delete;

	WindowMediaService(WindowMediaService &&) = delete;
	WindowMediaService &operator=(WindowMediaService &&) = delete;

	void registerListener(const IServiceListener *listener) override;
	void unregisterListener(const IServiceListener *listener) override;

	void start() override;
	void getMediaInfo() override;
	bool playAsync() override;
	bool pauseAsync() override;
	bool nextAsync() override;
	bool previousAsync() override;

	void systemMediaPropertiesChanged(const WMediaInfo &wMediaInfo);
	void systemPlaybackInfoChanged(const WPlaybackInfo &wPlaybackInfo);
	void systemTimelinePropertiesChanged(const WTimelineProperties &wTimelineProperties);

private:
	WindowSystemMediaUPtr m_systemMedia;
	std::vector<IServiceListener *> m_listeners; // TODO: change to map for faster access the listener
};

#endif // WINDOW_MEDIA_SERVICE_H
