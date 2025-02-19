/*
 * File: ViewModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModelController class
 */

#include "ViewModelController.h"
#include "view-models/mediaplayer/MediaPlayerViewModel.h"

ViewModelController::ViewModelController(QObject *parent)
    : QObject(parent)
    , m_mediaPlayerViewModel(std::make_shared<MediaPlayerViewModel>())
{
}

ViewModelController::~ViewModelController()
{
}

ViewModelController::MediaPlayerViewModelWPtr ViewModelController::getMediaPlayerViewModel() const
{
	return m_mediaPlayerViewModel;
}
