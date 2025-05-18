/*
 * File: WindowMediaService.cpp
 * Author: trung.la
 * Date: 02-07-2025
 * Description: This file contains the implementation of the WindowMediaService class
 */

#include "WindowMediaService.h"

#include <IWMediaServiceListener.h>

#include "WindowSystemMedia.h"

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
	m_systemMedia = std::make_unique<WindowSystemMedia>(this);
}

void WindowMediaService::stop()
{
	m_systemMedia.reset();
}

void WindowMediaService::getMediaInfo()
{
	// Get media information
}

bool WindowMediaService::playAsync()
{
	if (!m_systemMedia) {
		return false;
	}

	if (!m_systemMedia->tryPlayAsync()) {
		return false;
	}

	return true;
}

bool WindowMediaService::pauseAsync()
{
	if (!m_systemMedia) {
		return false;
	}

	if (!m_systemMedia->tryPauseAsync()) {
		return false;
	}

	return true;
}

bool WindowMediaService::nextAsync()
{
	if (!m_systemMedia) {
		return false;
	}

	if (!m_systemMedia->tryNextAsync()) {
		return false;
	}

	return true;
}

bool WindowMediaService::previousAsync()
{
	if (!m_systemMedia) {
		return false;
	}

	if (!m_systemMedia->tryPreviousAsync()) {
		return false;
	}

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

void WindowMediaService::systemPlaybackControlsChanged(const WPlaybackControls &wPlaybackControls)
{
	// Notify listeners about playback controls changed
	for (const auto &listener : m_listeners) {
		if (auto l = dynamic_cast<IWMediaServiceListener *>(listener)) {
			l->onPlaybackControlsChanged(wPlaybackControls);
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
