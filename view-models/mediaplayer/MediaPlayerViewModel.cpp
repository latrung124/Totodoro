/*
 * File: MediaPlayerViewModel.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: View Model for MediaPlayer
 */

#include "MediaPlayerViewModel.h"
#include "MediaPlaybackViewModel.h"

MediaPlayerViewModel::MediaPlayerViewModel(QObject *parent)
    : QObject(parent)
    , m_mediaPlaybackViewModel(std::make_unique<MediaPlaybackViewModel>())
{
	initDummyData();
}

MediaPlayerViewModel::~MediaPlayerViewModel()
{
}

void MediaPlayerViewModel::initDummyData()
{
	m_title = "Dummy Title";
	m_album = "Dummy Album";
	m_artist = "Dummy Artist";
	m_thumbnail = QUrl("qrc:/images/dummy_thumbnail.png");
}

QString MediaPlayerViewModel::title() const
{
	return m_title;
}

void MediaPlayerViewModel::setTitle(const QString &title)
{
	if (m_title != title) {
		m_title = title;
		emit titleChanged();
	}
}

QString MediaPlayerViewModel::album() const
{
	return m_album;
}

void MediaPlayerViewModel::setAlbum(const QString &album)
{
	if (m_album != album) {
		m_album = album;
		emit albumChanged();
	}
}

QString MediaPlayerViewModel::artist() const
{
	return m_artist;
}

void MediaPlayerViewModel::setArtist(const QString &artist)
{
	if (m_artist != artist) {
		m_artist = artist;
		emit artistChanged();
	}
}

QObject *MediaPlayerViewModel::mediaPlaybackViewModel() const
{
	return m_mediaPlaybackViewModel.get();
}

void MediaPlayerViewModel::setMediaPlaybackViewModel(QObject *mediaPlaybackViewModel)
{
	if (m_mediaPlaybackViewModel.get() != mediaPlaybackViewModel) {
		m_mediaPlaybackViewModel.reset(
		    qobject_cast<MediaPlaybackViewModel *>(mediaPlaybackViewModel));
		emit mediaPlaybackViewModelChanged();
	}
}

QUrl MediaPlayerViewModel::thumbnail() const
{
	return m_thumbnail;
}

void MediaPlayerViewModel::setThumbnail(const QUrl &thumbnail)
{
	if (m_thumbnail != thumbnail) {
		m_thumbnail = thumbnail;
		emit thumbnailChanged();
	}
}
