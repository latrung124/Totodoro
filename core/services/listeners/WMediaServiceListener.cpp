/*
 * File: WMediaServiceListener.cpp
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Interface for media service listener
 */

#include "WMediaServiceListener.h"

#include "core/services/producer/window-service/WMediaInfoMessageCreator.h"
#include "core/services/producer/window-service/WPlaybackControlsMessageCreator.h"
#include "core/services/producer/window-service/WPlaybackInfoMessageCreator.h"
#include "core/services/producer/window-service/WTimelinePropertiesMessageCreator.h"

#include "core/services/producer/ServiceMessageProducer.h"
#include "core/services/queue/MessageQueue.h"

void WMediaServiceListener::onMediaInfoChanged(const WMediaInfo &mediaInfo)
{
	auto message = ServiceMessageProducer::getInstance().produce<WMediaInfoMessageCreator>(
	    mediaInfo);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackControlsChanged(const WPlaybackControls &playbackControls)
{
	auto message = ServiceMessageProducer::getInstance().produce<WPlaybackControlsMessageCreator>(
	    playbackControls);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onPlaybackStatusChanged(const WPlaybackInfo &playbackInfo)
{
	auto message = ServiceMessageProducer::getInstance().produce<WPlaybackInfoMessageCreator>(
	    playbackInfo);
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}

void WMediaServiceListener::onTimelinePropertiesChanged(
    const WTimelineProperties &timelineProperties)
{
	auto message =
	    ServiceMessageProducer::getInstance().produce<WTimelinePropertiesMessageCreator>();
	if (message) {
		MessageQueue::getInstance().push(std::move(message));
	}
}
