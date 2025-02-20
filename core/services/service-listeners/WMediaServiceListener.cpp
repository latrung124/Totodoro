/*
 * File: WMediaServiceListener.cpp
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for media service listener
 */

#include "WMediaServiceListener.h"

#include "core/services/service-messages/ServiceMessageId.h"
#include "core/services/service-producer/ServiceMessageProducer.h"
#include "core/services/service-queue/ServiceMessageQueue.h"

void WMediaServiceListener::onMediaInfoChanged(const WMediaInfo &mediaInfo)
{
	auto message = ServiceMessageProducer::getInstance().produceMessage(
	    ServiceMessageId::WMediaInfoMessage);
	if (message) {
		ServiceMessageQueue::getInstance().addMessage(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackControlsChanged(const WPlaybackControls &playbackControls)
{
	auto message = ServiceMessageProducer::getInstance().produceMessage(
	    ServiceMessageId::WPlaybackControlsMessage);
	if (message) {
		ServiceMessageQueue::getInstance().addMessage(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackStatusChanged(const WPlaybackInfo &playbackInfo)
{
	auto message = ServiceMessageProducer::getInstance().produceMessage(
	    ServiceMessageId::WPlaybackInfoMessage);
	if (message) {
		ServiceMessageQueue::getInstance().addMessage(std::move(message));
	}
}
