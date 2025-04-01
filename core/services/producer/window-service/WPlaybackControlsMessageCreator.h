/*
 * File: WPlaybackControlsMessageCreator.h
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the declaration of the WPlaybackControlsMessageCreator class.
 */

#ifndef WPLAYBACK_CONTROLS_MESSAGE_CREATOR_H
#define WPLAYBACK_CONTROLS_MESSAGE_CREATOR_H

#include "core/services/producer/ServiceMessageCreator.h"

class WPlaybackControlsMessageCreator : public ServiceMessageCreator
{
public:
	virtual ~WPlaybackControlsMessageCreator() = default;

	ServiceMessageUPtr create() const override;
};

#endif // WPLAYBACK_CONTROLS_MESSAGE_CREATOR_H
