/*
 * File: ModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ModelController class
 */

#include "ModelController.h"

#include "models/mediaplayer/MediaPlayerModel.h"
#include "models/session/PomodoroModel.h"
#include "models/taskmanagement/TaskGroupModel.h"
#include "models/taskmanagement/TaskModel.h"
#include "models/userprofile/UserInformationModel.h"
#include "models/userprofile/UserSettingsModel.h"

ModelController &ModelController::getInstance()
{
	static ModelController instance;
	return instance;
}

ModelController::ModelController(QObject *parent)
    : QObject(parent)
    , m_mediaPlayerModel(std::make_shared<MediaPlayerModel>())
    , m_userInformationModel(std::make_shared<UserInformationModel>())
    , m_userSettingsModel(std::make_shared<UserSettingsModel>())
    , m_pomodoroModel(std::make_shared<PomodoroModel>())
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

ModelController::UserSettingsModelWPtr ModelController::getUserSettingsModel() const
{
	return m_userSettingsModel;
}

ModelController::PomodoroModelWPtr ModelController::getPomodoroModel() const
{
	return m_pomodoroModel;
}

ModelController::TaskModelWPtr ModelController::getTaskModel() const
{
	return m_taskModel;
}

ModelController::TaskGroupModelWPtr ModelController::getTaskGroupModel() const
{
	return m_taskGroupModel;
}
