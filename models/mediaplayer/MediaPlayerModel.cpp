/*
* File: MediaPlayerModel.cpp
* Author: trung.la
* Date: 02-05-2025
* Description: This file contains the implementation of the MediaPlayerModel class.
*/

#include "MediaPlayerModel.h"
#include "MediaPlaybackModel.h"

MediaPlayerModel::MediaPlayerModel()
    : m_mediaPlaybackModel(std::make_shared<MediaPlaybackModel>())
{
}

std::string MediaPlayerModel::title() const
{
    return m_title;
}

void MediaPlayerModel::setTitle(const std::string &title)
{
    if (m_title != title)
    {
        m_title = title;
    }
}

std::string MediaPlayerModel::artist() const
{
    return m_artist;
}

void MediaPlayerModel::setArtist(const std::string &artist)
{
    if (m_artist != artist)
    {
        m_artist = artist;
    }
}

std::string MediaPlayerModel::thumbnail() const
{
    return m_thumbnail;
}

void MediaPlayerModel::setThumbnail(const std::string &thumbnail)
{
    if (m_thumbnail != thumbnail)
    {
        m_thumbnail = thumbnail;
    }
}

MediaPlayerModel::MediaPlaybackModelPtr MediaPlayerModel::mediaPlaybackModel() const
{
    return m_mediaPlaybackModel;
}
