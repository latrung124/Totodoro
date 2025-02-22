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
    using GlobalSystemMediaTransportControlsSessionManager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
    using GlobalSystemMediaTransportControlsSession = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession;

    WindowSystemMedia(WindowMediaService *service);
    WindowSystemMedia() = delete;
    ~WindowSystemMedia();

    WindowSystemMedia(WindowSystemMedia &) = delete;
    WindowSystemMedia& operator=(const WindowSystemMedia &) = delete;

    WindowSystemMedia(WindowSystemMedia &&) = delete;
    WindowSystemMedia&& operator=(const WindowSystemMedia &&) = delete;

    bool init();

private:
    void registerCurrentSessionChangedEvents();
    void registerSessionPropertiesChangedEvents();

    void removeOldTempThumbnail();

    GlobalSystemMediaTransportControlsSessionManager m_sessionManager{ nullptr };
    GlobalSystemMediaTransportControlsSession m_session{ nullptr };

    WindowMediaService* m_service;
    std::string m_thumbnailPath = "";
};

#endif // WINDOW_SYSTEM_MEDIA_H