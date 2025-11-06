/*
 * File: WPlaybackControlsMessageCreator.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlaybackControlsMessageCreator class.
 */

#include "core/services/producer/window-service/WPlaybackControlsMessageCreator.h"
#include "core/services/messages/window-service/WPlaybackControlsMessage.h"
#include "core/services/strategies/window-service/WPlaybackControlsExtractStrategy.h"

ServiceMessageUPtr WPlaybackControlsMessageCreator::create(ParamContainerBase *param) const
{
	auto *container =
	    dynamic_cast<core::factories::ParamContainer<WPlaybackControlsMessage::WPlaybackControls> *>(
	        param);
	if (container == nullptr) {
		return std::make_unique<WPlaybackControlsMessage>(
		    std::make_unique<WPlaybackControlsExtractStrategy>());
	}

	const auto &playbackControls = container->getParam();

	auto message = std::make_unique<WPlaybackControlsMessage>(
	    std::make_unique<WPlaybackControlsExtractStrategy>());
	message->setWPlaybackControls(playbackControls);
	return message;
}
