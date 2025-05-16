/*
 * File: MediaPlaybackModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: This file contains the implementation of the MediaPlaybackModel class.
 */

#include "MediaPlaybackModel.h"

#include <QMetaObject>

#include "core/controllers/ViewModelController.h"
#include "view-models/mediaplayer/MediaPlayerViewModel.h"

MediaPlaybackModel::MediaPlaybackModel()
{
}

bool MediaPlaybackModel::isPlaying() const
{
	return m_isPlaying;
}

void MediaPlaybackModel::setIsPlaying(bool isPlaying)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_isPlaying != isPlaying) {
		m_isPlaying = isPlaying;
	}

	auto model = ViewModelController::getInstance().mediaPlayerViewModel();
	if (!model) {
		return;
	}

	if (auto playbackVM = model->mediaPlaybackViewModel()) {
		QMetaObject::invokeMethod(playbackVM, "onIsPlayingChanged", Q_ARG(bool, isPlaying));
	}
}

bool MediaPlaybackModel::isPlayingEnabled() const
{
	return m_isPlayingEnabled;
}

void MediaPlaybackModel::setIsPlayingEnabled(bool isPlayingEnabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_isPlayingEnabled != isPlayingEnabled) {
		m_isPlayingEnabled = isPlayingEnabled;
	}

	auto model = ViewModelController::getInstance().mediaPlayerViewModel();
	if (!model) {
		return;
	}

	if (auto playbackVM = model->mediaPlaybackViewModel()) {
		QMetaObject::invokeMethod(
		    playbackVM, "onIsPlayingEnabledChanged", Q_ARG(bool, isPlayingEnabled));
	}
}

bool MediaPlaybackModel::isPauseEnabled() const
{
	return m_isPauseEnabled;
}

void MediaPlaybackModel::setIsPauseEnabled(bool isPauseEnabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_isPauseEnabled != isPauseEnabled) {
		m_isPauseEnabled = isPauseEnabled;
	}

	auto model = ViewModelController::getInstance().mediaPlayerViewModel();
	if (!model) {
		return;
	}

	if (auto playbackVM = model->mediaPlaybackViewModel()) {
		QMetaObject::invokeMethod(
		    playbackVM, "onIsPauseEnabledChanged", Q_ARG(bool, isPauseEnabled));
	}
}

bool MediaPlaybackModel::isNextEnabled() const
{
	return m_isNextEnabled;
}

void MediaPlaybackModel::setIsNextEnabled(bool isNextEnabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_isNextEnabled != isNextEnabled) {
		m_isNextEnabled = isNextEnabled;
	}

	auto model = ViewModelController::getInstance().mediaPlayerViewModel();
	if (!model) {
		return;
	}

	if (auto playbackVM = model->mediaPlaybackViewModel()) {
		QMetaObject::invokeMethod(playbackVM, "onIsNextEnabledChanged", Q_ARG(bool, isNextEnabled));
	}
}

bool MediaPlaybackModel::isPreviousEnabled() const
{
	return m_isPreviousEnabled;
}

void MediaPlaybackModel::setIsPreviousEnabled(bool isPreviousEnabled)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_isPreviousEnabled != isPreviousEnabled) {
		m_isPreviousEnabled = isPreviousEnabled;
	}

	auto model = ViewModelController::getInstance().mediaPlayerViewModel();
	if (!model) {
		return;
	}

	if (auto playbackVM = model->mediaPlaybackViewModel()) {
		QMetaObject::invokeMethod(
		    playbackVM, "onIsPreviousEnabledChanged", Q_ARG(bool, isPreviousEnabled));
	}
}
