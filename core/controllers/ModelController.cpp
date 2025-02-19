/*
 * File: ModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ModelController class
 */

#include "ModelController.h"
#include "models/mediaplayer/MediaPlayerModel.h"

ModelController::ModelController(QObject *parent)
    : QObject(parent)
    , m_mediaPlayerModel(std::make_shared<MediaPlayerModel>())
{
}

ModelController::~ModelController()
{
}

ModelController::MediaPlayerModelWPtr ModelController::getMediaPlayerModel() const
{
	return m_mediaPlayerModel;
}
