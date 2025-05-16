/*
 * File: WPlaybackInfoExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackInfoExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPlaybackInfoExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"

#include "core/services/messages/window-service/WPlaybackInfoMessage.h"

#include "models/mediaplayer/MediaPlaybackModel.h"
#include "models/mediaplayer/MediaPlayerModel.h"

WPlaybackInfoExtractStrategy::~WPlaybackInfoExtractStrategy()
{
}

void WPlaybackInfoExtractStrategy::execute(const WPlaybackInfoMessage &message)
{
	extract(message);
}

void WPlaybackInfoExtractStrategy::extract(const WPlaybackInfoMessage &message)
{
	// TODO: consider to refactor because of too much dependency in strategy class
	using WMediaPlaybackStatus = window_services::media::utils::WMediaPlaybackStatus;

	qDebug() << "WPlaybackInfoExtractStrategy::extract";
	auto playbackInfo = message.getWPlaybackInfo();
	auto model = ModelController::getInstance().getMediaPlayerModel();
	if (auto modelPtr = model.lock()) {
		auto mediaPlaybackModel = modelPtr->mediaPlaybackModel();
		if (mediaPlaybackModel) {
			mediaPlaybackModel->setIsPlaying(
			    playbackInfo.playbackStatus == WMediaPlaybackStatus::Playing);
		} else {
			qDebug() << "MediaPlaybackModel is null";
		}
	} else {
		qDebug() << "MediaPlayerModel is null";
	}
}
