/*
 * File: WPlaybackControlsExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackControlsExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPlaybackControlsExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"
#include "core/services/messages/window-service/WPlaybackControlsMessage.h"

#include "models/mediaplayer/MediaPlaybackModel.h"
#include "models/mediaplayer/MediaPlayerModel.h"

WPlaybackControlsExtractStrategy::~WPlaybackControlsExtractStrategy()
{
}

void WPlaybackControlsExtractStrategy::execute(const WPlaybackControlsMessage &message)
{
	extract(message);
}

void WPlaybackControlsExtractStrategy::extract(const WPlaybackControlsMessage &message)
{
	// TODO: consider to refactor because of too much dependency in strategy class
	qDebug() << "WPlaybackControlsExtractStrategy::extract";
	auto playbackControls = message.getWPlaybackControls();
	auto model = ModelController::getInstance().getMediaPlayerModel(); // still in worker thread
	if (auto modelPtr = model.lock()) {
		auto mediaPlaybackModel = modelPtr->mediaPlaybackModel();
		if (mediaPlaybackModel) {
			mediaPlaybackModel->setIsPlayingEnabled(playbackControls.isPlayEnabled);
			mediaPlaybackModel->setIsPauseEnabled(playbackControls.isPauseEnabled);
			mediaPlaybackModel->setIsNextEnabled(playbackControls.isNextEnabled);
			mediaPlaybackModel->setIsPreviousEnabled(playbackControls.isPreviousEnabled);
		}
	} else {
		qDebug() << "Failed to lock MediaPlayerModel";
	}
}
