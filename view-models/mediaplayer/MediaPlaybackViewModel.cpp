/*
 * File: MediaPlaybackViewModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModel for MediaPlayback
 */

#include "MediaPlaybackViewModel.h"

#include "core/services/messages/window-service/WNextAsyncMessage.h"
#include "core/services/messages/window-service/WPauseAsyncMessage.h"
#include "core/services/messages/window-service/WPlayAsyncMessage.h"
#include "core/services/messages/window-service/WPreviousAsyncMessage.h"
#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/queue/MessageQueue.h"

namespace {
using ServiceMessageUPtr = std::unique_ptr<Message>;
}

MediaPlaybackViewModel::MediaPlaybackViewModel(QObject *parent)
    : ViewModel(parent)
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

void MediaPlaybackViewModel::play()
{
	ServiceMessageUPtr message = ServiceMessageProducer::getInstance().produce<WPlayAsyncMessage>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::pause()
{
	ServiceMessageUPtr message = ServiceMessageProducer::getInstance().produce<WPauseAsyncMessage>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::next()
{
	ServiceMessageUPtr message = ServiceMessageProducer::getInstance().produce<WNextAsyncMessage>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void MediaPlaybackViewModel::previous()
{
	ServiceMessageUPtr message =
	    ServiceMessageProducer::getInstance().produce<WPreviousAsyncMessage>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}
