/*
 * File: WindowMediaService.cpp
 * Author: trung.la
 * Date: 02-07-2025
 * Description: This file contains the implementation of the WindowMediaService class
 */

#include "WindowMediaService.h"

#include "WindowSystemMedia.h"
#include <IWMediaServiceListener.h>

WindowMediaService::WindowMediaService()
{
}

WindowMediaService::~WindowMediaService()
{
}

void WindowMediaService::registerListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (const auto &l : m_listeners) {
		if (l == listener) {
			return;
		}
	}

	m_listeners.push_back(const_cast<IServiceListener *>(listener));
}

void WindowMediaService::unregisterListener(const IServiceListener *listener)
{
	if (!listener) {
		return;
	}

	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it) {
		if (*it == listener) {
			m_listeners.erase(it);
			return;
		}
	}
}

void WindowMediaService::start()
{
	// Start the media service
	m_systemMedia = std::make_unique<WindowSystemMedia>(this);
}

void WindowMediaService::getMediaInfo()
{
	// Get media information
}

bool WindowMediaService::playAsync()
{
	// Play media asynchronously
	return true;
}

bool WindowMediaService::pauseAsync()
{
	// Pause media asynchronously
	return true;
}

bool WindowMediaService::nextAsync()
{
	// Play next media asynchronously
	return true;
}

bool WindowMediaService::previousAsync()
{
	// Play previous media asynchronously
	return true;
}

void WindowMediaService::systemMediaPropertiesChanged(const WMediaInfo &wMediaInfo)
{
	// Notify listeners about media properties changed
	for (const auto &listener : m_listeners) {
		if (auto l = dynamic_cast<IWMediaServiceListener *>(listener)) {
			l->onMediaInfoChanged(wMediaInfo);
		}
	}
}

void WindowMediaService::systemPlaybackInfoChanged(const WPlaybackInfo &wPlaybackInfo)
{
	// Notify listeners about playback info changed
	for (const auto &listener : m_listeners) {
		if (auto l = dynamic_cast<IWMediaServiceListener *>(listener)) {
			l->onPlaybackStatusChanged(wPlaybackInfo);
		}
	}
}

void WindowMediaService::systemTimelinePropertiesChanged(
    const WTimelineProperties &wTimelineProperties)
{
	// Notify listeners about timeline properties changed
	for (const auto &listener : m_listeners) {
		if (auto l = dynamic_cast<IWMediaServiceListener *>(listener)) {
			l->onTimelinePropertiesChanged(wTimelineProperties);
		}
	}
}
