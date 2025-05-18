/*
 * File: WindowSystemMedia.h
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the declaration of the WindowSystemMedia class.
 */

#ifndef WINDOW_SYSTEM_MEDIA_H
#define WINDOW_SYSTEM_MEDIA_H

#include <winrt/windows.media.control.h>

class WindowMediaService;

class WindowSystemMedia
{
public:
	using GlobalSystemMediaTransportControlsSessionManager =
	    winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
	using GlobalSystemMediaTransportControlsSession =
	    winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession;
	using IAsyncOperationBool = winrt::Windows::Foundation::IAsyncOperation<bool>;

	WindowSystemMedia(WindowMediaService *service);
	WindowSystemMedia() = delete;
	~WindowSystemMedia();

	WindowSystemMedia(WindowSystemMedia &) = delete;
	WindowSystemMedia &operator=(const WindowSystemMedia &) = delete;

	WindowSystemMedia(WindowSystemMedia &&) = delete;
	WindowSystemMedia &&operator=(const WindowSystemMedia &&) = delete;

	bool systemInit();

	IAsyncOperationBool tryPlayAsync();
	IAsyncOperationBool tryPauseAsync();
	IAsyncOperationBool tryNextAsync();
	IAsyncOperationBool tryPreviousAsync();

private:
	template<typename Properties>
	void updateMediaProperties(Properties &&properties);

	void registerCurrentSessionChangedEvents();
	void registerSessionPropertiesChangedEvents();

	void removeOldTempThumbnail();
	void getSyncMediaProperties(const GlobalSystemMediaTransportControlsSession &session);

	GlobalSystemMediaTransportControlsSessionManager m_sessionManager{nullptr};
	GlobalSystemMediaTransportControlsSession m_session{nullptr};

	WindowMediaService *m_service;
	std::string m_thumbnailPath = "";
};

#endif // WINDOW_SYSTEM_MEDIA_H
