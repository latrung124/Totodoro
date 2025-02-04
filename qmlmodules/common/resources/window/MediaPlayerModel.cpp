/*
* File: MediaPlayerModel.cpp
* Author: trung.la
* Date: 01-17-2025
* Description: Implementation for Media Player Model
*/

#include "MediaModule/MediaPlayerModel.h"

#include <iomanip>
#include <sstream>

namespace {

double convert100nsToSeconds(int64_t timeIn100ns) {
    return static_cast<double>(timeIn100ns) / 10'000'000.0;
}

std::string convertToMinutesSeconds(int64_t timeIn100ns) {
    auto seconds = convert100nsToSeconds(timeIn100ns);
    auto minutes = static_cast<int>(seconds / 60);
    auto remainingSeconds = static_cast<int>(seconds) % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << remainingSeconds;

    return oss.str();
}

double calculateProgress(int64_t positionIn100ns, int64_t durationIn100ns) {
    double duration = convert100nsToSeconds(durationIn100ns);
    double position = convert100nsToSeconds(positionIn100ns);
    if (duration <= 0) return 0.0;  // Prevent division by zero
    return (static_cast<double>(position) / duration) * 100.0;
}

}

MediaPlayerModel::MediaPlayerModel(QObject *parent)
    : QObject(parent)
{
}

MediaPlayerModel::~MediaPlayerModel()
{
}

void MediaPlayerModel::updateMediaInfo(const WindowServiceUtils::WMediaInfo &wMediaInfo)
{
    setTitle(QString::fromStdString(wMediaInfo.title));
    setArtist(QString::fromStdString(wMediaInfo.artist));
    setAlbumTitle(QString::fromStdString(wMediaInfo.albumTitle));
    setAlbumArtist(QString::fromStdString(wMediaInfo.albumArtist));
    setSubtitle(QString::fromStdString(wMediaInfo.subtitle));
    // setGenres(QString::fromStdString(wMediaInfo.genres));
    setTotalTracks(wMediaInfo.totalTracks);
    setTrackNumber(wMediaInfo.trackNumber);
    setThumbnail(QUrl::fromLocalFile(QString::fromStdString(wMediaInfo.thumbnail)));
}

void MediaPlayerModel::updatePlaybackInfo(const WindowServiceUtils::WPlaybackInfo &playbackInfo)
{
    auto isPlaying = playbackInfo.playbackStatus == WindowServiceUtils::WMediaPlaybackStatus::Playing;
    setIsPlaying(isPlaying);
    setIsNextEnabled(playbackInfo.playbackControls.isNextEnabled);
    setIsPreviousEnabled(playbackInfo.playbackControls.isPreviousEnabled);
    setIsPauseEnabled(playbackInfo.playbackControls.isPauseEnabled);
    setIsPlayEnabled(playbackInfo.playbackControls.isPlayEnabled);
    setIsRepeatEnabled(playbackInfo.playbackControls.isRepeatEnabled);
    setIsShuffleEnabled(playbackInfo.isShuffled);
}

void MediaPlayerModel::updateTimelineProperties(const WindowServiceUtils::WTimelineProperties &timelineProperties)
{
    setStartTime(QString::fromStdString(convertToMinutesSeconds(timelineProperties.startTime)));
    setEndTime(QString::fromStdString(convertToMinutesSeconds(timelineProperties.endTime)));
    setPosition(calculateProgress(timelineProperties.position, timelineProperties.endTime));
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
        emit titleChanged();
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
        emit artistChanged();
    }
}

QString MediaPlayerModel::albumTitle() const
{
    return m_albumTitle;
}

void MediaPlayerModel::setAlbumTitle(const QString &albumTitle)
{
    if (m_albumTitle != albumTitle)
    {
        m_albumTitle = albumTitle;
        emit albumTitleChanged();
    }
}

QString MediaPlayerModel::albumArtist() const
{
    return m_albumArtist;
}

void MediaPlayerModel::setAlbumArtist(const QString &albumArtist)
{
    if (m_albumArtist != albumArtist)
    {
        m_albumArtist = albumArtist;
        emit albumArtistChanged();
    }
}

QString MediaPlayerModel::subtitle() const
{
    return m_subtitle;
}

void MediaPlayerModel::setSubtitle(const QString &subtitle)
{
    if (m_subtitle != subtitle)
    {
        m_subtitle = subtitle;
        emit subtitleChanged();
    }
}

QString MediaPlayerModel::genres() const
{
    return m_genres;
}

void MediaPlayerModel::setGenres(const QString &genres)
{
    if (m_genres != genres)
    {
        m_genres = genres;
        emit genresChanged();
    }
}

int MediaPlayerModel::totalTracks() const
{
    return m_totalTracks;
}

void MediaPlayerModel::setTotalTracks(int totalTracks)
{
    if (m_totalTracks != totalTracks)
    {
        m_totalTracks = totalTracks;
        emit totalTracksChanged();
    }
}

int MediaPlayerModel::trackNumber() const
{
    return m_trackNumber;
}

void MediaPlayerModel::setTrackNumber(int trackNumber)
{
    if (m_trackNumber != trackNumber)
    {
        m_trackNumber = trackNumber;
        emit trackNumberChanged();
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
        emit thumbnailChanged();
    }
}

bool MediaPlayerModel::isPlaying() const
{
    return m_isPlaying;
}

void MediaPlayerModel::setIsPlaying(bool isPlaying)
{
    if (m_isPlaying != isPlaying)
    {
        m_isPlaying = isPlaying;
        emit isPlayingChanged();
    }
}

bool MediaPlayerModel::isNextEnabled() const
{
    return m_isNextEnabled;
}

void MediaPlayerModel::setIsNextEnabled(bool isNextEnabled)
{
    if (m_isNextEnabled != isNextEnabled)
    {
        m_isNextEnabled = isNextEnabled;
        emit isNextEnabledChanged();
    }
}

bool MediaPlayerModel::isPreviousEnabled() const
{
    return m_isPreviousEnabled;
}

void MediaPlayerModel::setIsPreviousEnabled(bool isPreviousEnabled)
{
    if (m_isPreviousEnabled != isPreviousEnabled)
    {
        m_isPreviousEnabled = isPreviousEnabled;
        emit isPreviousEnabledChanged();
    }
}

bool MediaPlayerModel::isPauseEnabled() const
{
    return m_isPauseEnabled;
}

void MediaPlayerModel::setIsPauseEnabled(bool isPauseEnabled)
{
    if (m_isPauseEnabled != isPauseEnabled)
    {
        m_isPauseEnabled = isPauseEnabled;
        emit isPauseEnabledChanged();
    }
}

bool MediaPlayerModel::isPlayEnabled() const
{
    return m_isPlayEnabled;
}

void MediaPlayerModel::setIsPlayEnabled(bool isPlayEnabled)
{
    if (m_isPlayEnabled != isPlayEnabled)
    {
        m_isPlayEnabled = isPlayEnabled;
        emit isPlayEnabledChanged();
    }
}

bool MediaPlayerModel::isRepeatEnabled() const
{
    return m_isRepeatEnabled;
}

void MediaPlayerModel::setIsRepeatEnabled(bool isRepeatEnabled)
{
    if (m_isRepeatEnabled != isRepeatEnabled)
    {
        m_isRepeatEnabled = isRepeatEnabled;
        emit isRepeatEnabledChanged();
    }
}

bool MediaPlayerModel::isShuffleEnabled() const
{
    return m_isShuffleEnabled;
}

void MediaPlayerModel::setIsShuffleEnabled(bool isShuffleEnabled)
{
    if (m_isShuffleEnabled != isShuffleEnabled)
    {
        m_isShuffleEnabled = isShuffleEnabled;
        emit isShuffleEnabledChanged();
    }
}

void MediaPlayerModel::setPosition(double position)
{
    if (m_position != position)
    {
        m_position = position;
        emit positionChanged();
    }
}

double MediaPlayerModel::position() const
{
    return m_position;
}

QString MediaPlayerModel::startTime() const
{
    return m_startTime;
}

void MediaPlayerModel::setStartTime(const QString &startTime)
{
    if (m_startTime != startTime)
    {
        m_startTime = startTime;
        emit startTimeChanged();
    }
}

QString MediaPlayerModel::endTime() const
{
    return m_endTime;
}

void MediaPlayerModel::setEndTime(const QString &endTime)
{
    if (m_endTime != endTime)
    {
        m_endTime = endTime;
        emit endTimeChanged();
    }
}