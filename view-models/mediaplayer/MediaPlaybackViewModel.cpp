/*
 * File: MediaPlaybackViewModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: View Model for MediaPlayback
 */

#include "MediaPlaybackViewModel.h"

#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/queue/MessageQueue.h"

#include "core/services/producer/window-service/WNextAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPauseAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPlayAsyncMessageCreator.h"
#include "core/services/producer/window-service/WPreviousAsyncMessageCreator.h"

#include "models/mediaplayer/MediaPlaybackModel.h"

namespace {
using ServiceMessageUPtr = std::unique_ptr<Message>;
}

MediaPlaybackViewModel::MediaPlaybackViewModel(QObject *parent)
    : QObject(parent)
{
	initDummyData();
}

MediaPlaybackViewModel::~MediaPlaybackViewModel()
{
}

void MediaPlaybackViewModel::initDummyData()
{
	m_isPlaying = false;
	m_isPlayingEnabled = true;
	m_isPauseEnabled = true;
	m_isNextEnabled = true;
	m_isPreviousEnabled = true;
	m_isShuffleEnabled = false;
	m_isRepeatEnabled = false;
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

bool MediaPlaybackViewModel::isShuffleEnabled() const
{
	return m_isShuffleEnabled;
}

void MediaPlaybackViewModel::setIsShuffleEnabled(bool isShuffleEnabled)
{
	if (m_isShuffleEnabled != isShuffleEnabled) {
		m_isShuffleEnabled = isShuffleEnabled;
		emit isShuffleEnabledChanged();
	}
}

bool MediaPlaybackViewModel::isRepeatEnabled() const
{
	return m_isRepeatEnabled;
}

void MediaPlaybackViewModel::setIsRepeatEnabled(bool isRepeatEnabled)
{
	if (m_isRepeatEnabled != isRepeatEnabled) {
		m_isRepeatEnabled = isRepeatEnabled;
		emit isRepeatEnabledChanged();
	}
}

void MediaPlaybackViewModel::play()
{
	if ((m_isPlaying && m_isPlayingEnabled) || !m_isPlayingEnabled) {
		return;
	}

	// TODO: Implement another MessageQueue for requesting, that will be distinguished from
	// the response queue
	ServiceMessageUPtr message =
	    ServiceMessageProducer::getInstance().produce<WPlayAsyncMessageCreator>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::pause()
{
	if (!m_isPlaying || !m_isPauseEnabled) {
		return;
	}

	// TODO: Implement another MessageQueue for requesting, that will be distinguished from
	// the response queue
	ServiceMessageUPtr message =
	    ServiceMessageProducer::getInstance().produce<WPauseAsyncMessageCreator>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::next()
{
	// TODO: Implement another MessageQueue for requesting, that will be distinguished from
	// the response queue
	ServiceMessageUPtr message =
	    ServiceMessageProducer::getInstance().produce<WNextAsyncMessageCreator>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::previous()
{
	// TODO: Implement another MessageQueue for requesting, that will be distinguished from
	// the response queue
	ServiceMessageUPtr message =
	    ServiceMessageProducer::getInstance().produce<WPreviousAsyncMessageCreator>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::shuffle()
{
	// TODO:Implement shuffle logic here
}

void MediaPlaybackViewModel::repeat()
{
	// TODO:Implement repeat logic here
}

void MediaPlaybackViewModel::onIsPlayingChanged(bool isPlaying)
{
	setIsPlaying(isPlaying);
}

void MediaPlaybackViewModel::onIsPlayingEnabledChanged(bool isPlayingEnabled)
{
	setIsPlayingEnabled(isPlayingEnabled);
}

void MediaPlaybackViewModel::onIsPauseEnabledChanged(bool isPauseEnabled)
{
	setIsPauseEnabled(isPauseEnabled);
}

void MediaPlaybackViewModel::onIsNextEnabledChanged(bool isNextEnabled)
{
	setIsNextEnabled(isNextEnabled);
}

void MediaPlaybackViewModel::onIsPreviousEnabledChanged(bool isPreviousEnabled)
{
	setIsPreviousEnabled(isPreviousEnabled);
}

void MediaPlaybackViewModel::updateMediaPlaybackFromModel(const MediaPlaybackModel &model)
{
	setIsPlaying(model.isPlaying());
	setIsPlayingEnabled(model.isPlayingEnabled());
	setIsPauseEnabled(model.isPauseEnabled());
	setIsNextEnabled(model.isNextEnabled());
	setIsPreviousEnabled(model.isPreviousEnabled());
}
