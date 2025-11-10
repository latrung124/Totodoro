/*
 * File: ModelController.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ModelController class
 */

#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>

#include <memory>

class MediaPlayerModel;
class UserInformationModel;
class UserSettingsModel;
class PomodoroModel;
class TaskModel;
class TaskGroupModel;

class ModelController : public QObject
{
	Q_OBJECT

public:
	using MediaPlayerModelPtr = std::shared_ptr<MediaPlayerModel>;
	using MediaPlayerModelWPtr = std::weak_ptr<MediaPlayerModel>;
	using UserInformationModelPtr = std::shared_ptr<UserInformationModel>;
	using UserInformationModelWPtr = std::weak_ptr<UserInformationModel>;
	using UserSettingsModelPtr = std::shared_ptr<UserSettingsModel>;
	using UserSettingsModelWPtr = std::weak_ptr<UserSettingsModel>;
	using PomodoroModelPtr = std::shared_ptr<PomodoroModel>;
	using PomodoroModelWPtr = std::weak_ptr<PomodoroModel>;
	using TaskModelPtr = std::shared_ptr<TaskModel>;
	using TaskModelWPtr = std::weak_ptr<TaskModel>;
	using TaskGroupModelPtr = std::shared_ptr<TaskGroupModel>;
	using TaskGroupModelWPtr = std::weak_ptr<TaskGroupModel>;

	static ModelController &getInstance();

	~ModelController();

	MediaPlayerModelWPtr getMediaPlayerModel() const;
	UserInformationModelWPtr getUserInformationModel() const;
	UserSettingsModelWPtr getUserSettingsModel() const;
	PomodoroModelWPtr getPomodoroModel() const;
	TaskModelWPtr getTaskModel() const;
	TaskGroupModelWPtr getTaskGroupModel() const;

private:
	explicit ModelController(QObject *parent = nullptr);

	void initConnections();
	void deinitConnections();

	MediaPlayerModelPtr m_mediaPlayerModel;
	UserInformationModelPtr m_userInformationModel;
	UserSettingsModelPtr m_userSettingsModel;
	PomodoroModelPtr m_pomodoroModel;
	TaskModelPtr m_taskModel;
	TaskGroupModelPtr m_taskGroupModel;
};

#endif // MODELCONTROLLER_H
