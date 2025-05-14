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

class ModelController : public QObject
{
	Q_OBJECT

public:
	using MediaPlayerModelPtr = std::shared_ptr<MediaPlayerModel>;
	using MediaPlayerModelWPtr = std::weak_ptr<MediaPlayerModel>;

	static ModelController &getInstance();

	~ModelController();

	MediaPlayerModelWPtr getMediaPlayerModel() const;

private:
	explicit ModelController(QObject *parent = nullptr);

	void initConnections();
	void deinitConnections();

	MediaPlayerModelPtr m_mediaPlayerModel;
};

#endif // MODELCONTROLLER_H
