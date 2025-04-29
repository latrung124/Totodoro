/*
 * File: MediaPlayerVMProducer.cpp
 * Author: trung.la
 * Date: 04-26-2025
 * Description: MediaPlayerVMProducer class definition
 * This class is responsible for creating MediaPlayerViewModel instances.
 */

#include "MediaPlayerVMProducer.h"

#include "helpers/ParamContainerHelper.h"

#include "view-models/mediaplayer/MediaPlayerViewModel.h"

std::unique_ptr<QObject> MediaPlayerVMProducer::createViewModel(ParamContainerBase *params)
{
	return std::make_unique<MediaPlayerViewModel>();
}
