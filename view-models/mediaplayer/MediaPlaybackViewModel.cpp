/*
 * File: MediaPlaybackViewModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModel for MediaPlayback
 */

#include "MediaPlaybackViewModel.h"

MediaPlaybackViewModel::MediaPlaybackViewModel(QObject *parent)
    : QObject(parent)
{
}

MediaPlaybackViewModel::~MediaPlaybackViewModel()
{
}

bool MediaPlaybackViewModel::isPlaying() const
{
	return m_isPlaying;
}

void MediaPlaybackViewModel::setIsPlaying(bool isPlaying)
{
	if (m_isPlaying != isPlaying) {
		m_isPlaying = isPlaying;
		emit isPlayingChanged();
	}
}

bool MediaPlaybackViewModel::isPlayingEnabled() const
{
	return m_isPlayingEnabled;
}

void MediaPlaybackViewModel::setIsPlayingEnabled(bool isPlayingEnabled)
{
	if (m_isPlayingEnabled != isPlayingEnabled) {
		m_isPlayingEnabled = isPlayingEnabled;
		emit isPlayingEnabledChanged();
	}
}

bool MediaPlaybackViewModel::isPauseEnabled() const
{
	return m_isPauseEnabled;
}

void MediaPlaybackViewModel::setIsPauseEnabled(bool isPauseEnabled)
{
	if (m_isPauseEnabled != isPauseEnabled) {
		m_isPauseEnabled = isPauseEnabled;
		emit isPauseEnabledChanged();
	}
}

bool MediaPlaybackViewModel::isNextEnabled() const
{
	return m_isNextEnabled;
}

void MediaPlaybackViewModel::setIsNextEnabled(bool isNextEnabled)
{
	if (m_isNextEnabled != isNextEnabled) {
		m_isNextEnabled = isNextEnabled;
		emit isNextEnabledChanged();
	}
}

bool MediaPlaybackViewModel::isPreviousEnabled() const
{
	return m_isPreviousEnabled;
}

void MediaPlaybackViewModel::setIsPreviousEnabled(bool isPreviousEnabled)
{
	if (m_isPreviousEnabled != isPreviousEnabled) {
		m_isPreviousEnabled = isPreviousEnabled;
		emit isPreviousEnabledChanged();
	}
}

void MediaPlaybackViewModel::onIsPlayingChanged(bool isPlaying)
{
	setIsPlaying(isPlaying);
}

void MediaPlaybackViewModel::onIsPlayingEnabledChanged(bool isPlayingEnabled)
{
	setIsPlayingEnabled(isPlayingEnabled);
}

void MediaPlaybackViewModel::onIsPausedEnabledChanged(bool isPausedEnabled)
{
	setIsPauseEnabled(isPausedEnabled);
}

void MediaPlaybackViewModel::onIsNextEnabledChanged(bool isNextEnabled)
{
	setIsNextEnabled(isNextEnabled);
}

void MediaPlaybackViewModel::onIsPreviousEnabledChanged(bool isPreviousEnabled)
{
	setIsPreviousEnabled(isPreviousEnabled);
}
