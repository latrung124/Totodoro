/*
* File: ConnectionManager.cpp
* Author: trung.la
* Date: 02-05-2025
* Description: ConnectionManager class
*/

#include "ConnectionManager.h"

#include "core/controllers/ViewModelController.h"
#include "core/controllers/ModelController.h"

#include "models/mediaplayer/MediaPlayerModel.h"
#include "models/mediaplayer/MediaPlaybackModel.h"
#include "view-models/mediaplayer/MediaPlayerViewModel.h"
#include "view-models/mediaplayer/MediaPlaybackViewModel.h"

#include <QObject>

ConnectionManager::ConnectionManager()
{
}

ConnectionManager::~ConnectionManager()
{
}

void ConnectionManager::connectViewModelAndModel(ViewModelController *viewModelController, ModelController *modelController)
{
    auto mediaPlayerViewModelPtr = viewModelController->getMediaPlayerViewModel().lock();
    auto mediaPlayerModelPtr = modelController->getMediaPlayerModel().lock();
    bool mediaModelConnection = mediaPlayerModelPtr != nullptr && mediaPlayerViewModelPtr != nullptr;
    if (mediaModelConnection)
    {
        // ViewModel -> Model
        QObject::connect(mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::viewTitleChanged, mediaPlayerModelPtr.get(), &MediaPlayerModel::onTitleChanged);
        QObject::connect(mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::viewArtistChanged, mediaPlayerModelPtr.get(), &MediaPlayerModel::onArtistChanged);
        QObject::connect(mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::viewThumbnailChanged, mediaPlayerModelPtr.get(), &MediaPlayerModel::onThumbnailChanged);

        // Model -> ViewModel
        QObject::connect(mediaPlayerModelPtr.get(), &MediaPlayerModel::titleChanged, mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::onTitleChanged, Qt::QueuedConnection);
        QObject::connect(mediaPlayerModelPtr.get(), &MediaPlayerModel::artistChanged, mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::onArtistChanged, Qt::QueuedConnection);
        QObject::connect(mediaPlayerModelPtr.get(), &MediaPlayerModel::thumbnailChanged, mediaPlayerViewModelPtr.get(), &MediaPlayerViewModel::onThumbnailChanged, Qt::QueuedConnection);
    }
}
