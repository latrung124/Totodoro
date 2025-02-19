/*
 * File: MediaPlayerModel.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: This file contains the declaration of the MediaPlayerModel class.
 */

#ifndef MEDIAPLAYERMODEL_H
#define MEDIAPLAYERMODEL_H

#include "models/SystemDataModel.h"

#include <memory>
#include <string>

class MediaPlaybackModel;

class MediaPlayerModel : public SystemDataModel
{
public:
	using MediaPlaybackModelPtr = std::shared_ptr<MediaPlaybackModel>;

	explicit MediaPlayerModel();
	~MediaPlayerModel() = default;

	std::string title() const;
	void setTitle(const std::string &title);

	std::string artist() const;
	void setArtist(const std::string &artist);

	std::string thumbnail() const;
	void setThumbnail(const std::string &thumbnail);

	MediaPlaybackModelPtr mediaPlaybackModel() const;

private:
	std::string m_title;
	std::string m_artist;
	std::string m_thumbnail;
	MediaPlaybackModelPtr m_mediaPlaybackModel;
};

#endif // MEDIAPLAYERMODEL_H
