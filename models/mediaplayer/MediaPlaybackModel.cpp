/*
 * File: MediaPlaybackModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: This file contains the implementation of the MediaPlaybackModel class.
 */

#include "MediaPlaybackModel.h"

MediaPlaybackModel::MediaPlaybackModel()
{
}

bool MediaPlaybackModel::isPlaying() const
{
	return m_isPlaying;
}

void MediaPlaybackModel::setIsPlaying(bool isPlaying)
{
	if (m_isPlaying != isPlaying) {
		m_isPlaying = isPlaying;
	}
}

bool MediaPlaybackModel::isPlayingEnabled() const
{
	return m_isPlayingEnabled;
}

void MediaPlaybackModel::setIsPlayingEnabled(bool isPlayingEnabled)
{
	if (m_isPlayingEnabled != isPlayingEnabled) {
		m_isPlayingEnabled = isPlayingEnabled;
	}
}

bool MediaPlaybackModel::isPauseEnabled() const
{
	return m_isPauseEnabled;
}

void MediaPlaybackModel::setIsPauseEnabled(bool isPauseEnabled)
{
	if (m_isPauseEnabled != isPauseEnabled) {
		m_isPauseEnabled = isPauseEnabled;
	}
}

bool MediaPlaybackModel::isNextEnabled() const
{
	return m_isNextEnabled;
}

void MediaPlaybackModel::setIsNextEnabled(bool isNextEnabled)
{
	if (m_isNextEnabled != isNextEnabled) {
		m_isNextEnabled = isNextEnabled;
	}
}

bool MediaPlaybackModel::isPreviousEnabled() const
{
	return m_isPreviousEnabled;
}

void MediaPlaybackModel::setIsPreviousEnabled(bool isPreviousEnabled)
{
	if (m_isPreviousEnabled != isPreviousEnabled) {
		m_isPreviousEnabled = isPreviousEnabled;
	}
}
