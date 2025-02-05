/*
* File: MediaPlayerModel.cpp
* Author: trung.la
* Date: 02-05-2025
* Description: This file contains the implementation of the MediaPlayerModel class.
*/

#include "MediaPlayerModel.h"
#include "MediaPlaybackModel.h"

MediaPlayerModel::MediaPlayerModel(QObject* parent)
    : QObject(parent)
    , m_mediaPlaybackModel(std::make_shared<MediaPlaybackModel>())
{
}

QString MediaPlayerModel::title() const
{
    return m_title;
}

void MediaPlayerModel::setTitle(const QString &title)
{
    if (m_title != title)
    {
        m_title = title;
        emit titleChanged(title);
    }
}

QString MediaPlayerModel::artist() const
{
    return m_artist;
}

void MediaPlayerModel::setArtist(const QString &artist)
{
    if (m_artist != artist)
    {
        m_artist = artist;
        emit artistChanged(artist);
    }
}

QUrl MediaPlayerModel::thumbnail() const
{
    return m_thumbnail;
}

void MediaPlayerModel::setThumbnail(const QUrl &thumbnail)
{
    if (m_thumbnail != thumbnail)
    {
        m_thumbnail = thumbnail;
        emit thumbnailChanged(thumbnail);
    }
}

MediaPlayerModel::MediaPlaybackModelPtr MediaPlayerModel::mediaPlaybackModel() const
{
    return m_mediaPlaybackModel;
}