/*
 * File: ModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ModelController class
 */

#include "ModelController.h"

#include "core/controllers/ViewModelController.h"

#include "models/mediaplayer/MediaPlayerModel.h"
#include "models/userprofile/UserInformationModel.h"

ModelController &ModelController::getInstance()
{
	static ModelController instance;
	return instance;
}

ModelController::ModelController(QObject *parent)
    : QObject(parent)
    , m_mediaPlayerModel(std::make_shared<MediaPlayerModel>())
    , m_userInformationModel(std::make_shared<UserInformationModel>())
{
	initConnections();
}

ModelController::~ModelController()
{
	deinitConnections();
}

void ModelController::initConnections()
{
}

void ModelController::deinitConnections()
{
}

ModelController::MediaPlayerModelWPtr ModelController::getMediaPlayerModel() const
{
	return m_mediaPlayerModel;
}

ModelController::UserInformationModelWPtr ModelController::getUserInformationModel() const
{
	return m_userInformationModel;
}
