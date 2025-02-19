/*
 * File: ModelController.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ModelController class
 */

#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <memory>

#include <QObject>

class MediaPlayerModel;

class ModelController : public QObject
{
public:
	using MediaPlayerModelPtr = std::shared_ptr<MediaPlayerModel>;
	using MediaPlayerModelWPtr = std::weak_ptr<MediaPlayerModel>;

	explicit ModelController(QObject *parent = nullptr);
	~ModelController();

	MediaPlayerModelWPtr getMediaPlayerModel() const;

private:
	MediaPlayerModelPtr m_mediaPlayerModel;
};

#endif // MODELCONTROLLER_H
