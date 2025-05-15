/*
 * File: MediaPlayerModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: This file contains the implementation of the MediaPlayerModel class.
 */

#include "MediaPlayerModel.h"

#include <QMetaObject>
#include <QString>

#include "MediaPlaybackModel.h"
#include "view-models/mediaplayer/MediaPlayerViewModel.h"

#include "core/controllers/ViewModelController.h"

MediaPlayerModel::MediaPlayerModel()
    : m_mediaPlaybackModel(std::make_shared<MediaPlaybackModel>())
{
}

std::string MediaPlayerModel::title() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_title;
}

void MediaPlayerModel::setTitle(const std::string &title)
{
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_title != title) {
			m_title = title;
		}
	}

	auto viewModel = ViewModelController::getInstance().mediaPlayerViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onTitleChanged", Q_ARG(QString, QString::fromStdString(m_title)));
	}
}

std::string MediaPlayerModel::artist() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_artist;
}

void MediaPlayerModel::setArtist(const std::string &artist)
{
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_artist != artist) {
			m_artist = artist;
		}
	}

	auto viewModel = ViewModelController::getInstance().mediaPlayerViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onArtistChanged", Q_ARG(QString, QString::fromStdString(m_artist)));
	}
}

std::string MediaPlayerModel::album() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_album;
}

void MediaPlayerModel::setAlbum(const std::string &album)
{
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_album != album) {
			m_album = album;
		}
	}

	auto viewModel = ViewModelController::getInstance().mediaPlayerViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel, "onAlbumChanged", Q_ARG(QString, QString::fromStdString(m_album)));
	}
}

std::string MediaPlayerModel::thumbnail() const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_thumbnail;
}

void MediaPlayerModel::setThumbnail(const std::string &thumbnail)
{
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_thumbnail != thumbnail) {
			m_thumbnail = thumbnail;
		}
	}

	auto viewModel = ViewModelController::getInstance().mediaPlayerViewModel();
	if (viewModel) {
		QMetaObject::invokeMethod(
		    viewModel,
		    "onThumbnailChanged",
		    Q_ARG(QUrl, QUrl::fromLocalFile(QString::fromStdString(m_thumbnail))));
	}
}

MediaPlayerModel::MediaPlaybackModelPtr MediaPlayerModel::mediaPlaybackModel() const
{
	return m_mediaPlaybackModel;
}
