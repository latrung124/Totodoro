/*
 * File: WMediaServiceListener.cpp
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for media service listener
 */

#include "WMediaServiceListener.h"

#include "core/services/messages/window-service/WMediaInfoMessage.h"
#include "core/services/messages/window-service/WPlaybackControlsMessage.h"
#include "core/services/messages/window-service/WPlaybackInfoMessage.h"
#include "core/services/messages/window-service/WTimelinePropertiesMessage.h"
#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/queue/ServiceMessageQueue.h"

void WMediaServiceListener::onMediaInfoChanged(const WMediaInfo &mediaInfo)
{
	auto message = ServiceMessageProducer::getInstance().produce<WMediaInfoMessage>();
	if (message) {
		ServiceMessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackControlsChanged(const WPlaybackControls &playbackControls)
{
	auto message = ServiceMessageProducer::getInstance().produce<WPlaybackControls>();
	if (message) {
		ServiceMessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackStatusChanged(const WPlaybackInfo &playbackInfo)
{
	auto message = ServiceMessageProducer::getInstance().produce<WPlaybackInfoMessage>();
	if (message) {
		ServiceMessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onTimelinePropertiesChanged(
    const WTimelineProperties &timelineProperties)
{
	auto message = ServiceMessageProducer::getInstance().produce<WTimelinePropertiesMessage>();
	if (message) {
		ServiceMessageQueue::getInstance().push(std::move(message));
	}
}
