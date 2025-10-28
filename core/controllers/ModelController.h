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

class ModelController : public QObject
{
	Q_OBJECT

public:
	using MediaPlayerModelPtr = std::shared_ptr<MediaPlayerModel>;
	using MediaPlayerModelWPtr = std::weak_ptr<MediaPlayerModel>;
	using UserInformationModelPtr = std::shared_ptr<UserInformationModel>;
	using UserInformationModelWPtr = std::weak_ptr<UserInformationModel>;

	static ModelController &getInstance();

	~ModelController();

	MediaPlayerModelWPtr getMediaPlayerModel() const;
	UserInformationModelWPtr getUserInformationModel() const;

private:
	explicit ModelController(QObject *parent = nullptr);

	void initConnections();
	void deinitConnections();

	MediaPlayerModelPtr m_mediaPlayerModel;
	UserInformationModelPtr m_userInformationModel;
};

#endif // MODELCONTROLLER_H
