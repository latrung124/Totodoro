/*
* File: MediaPlaybackModel.h
* Author: trung.la
* Date: 02-05-2025
* Description: This file contains the declaration of the MediaPlaybackModel class.
*/

#ifndef MEDIAPLAYBACKMODEL_H
#define MEDIAPLAYBACKMODEL_H

#include "models/SystemDataModel.h"

class MediaPlaybackModel : public SystemDataModel
{
    Q_OBJECT

public:
    MediaPlaybackModel(QObject *parent = nullptr);
    ~MediaPlaybackModel() = default;

    bool isPlaying() const;
    void setIsPlaying(bool isPlaying);

    bool isPlayingEnabled() const;
    void setIsPlayingEnabled(bool isPlayingEnabled);

    bool isPauseEnabled() const;
    void setIsPauseEnabled(bool isPauseEnabled);

    bool isNextEnabled() const;
    void setIsNextEnabled(bool isNextEnabled);

    bool isPreviousEnabled() const;
    void setIsPreviousEnabled(bool isPreviousEnabled);

signals:
    void isPlayingChanged(bool isPlaying);
    void isPlayingEnabledChanged(bool isPlayingEnabled);
    void isPauseEnabledChanged(bool isPauseEnabled);
    void isNextEnabledChanged(bool isNextEnabled);
    void isPreviousEnabledChanged(bool isPreviousEnabled);

private:
    bool m_isPlaying = false;
    bool m_isPlayingEnabled = false;
    bool m_isPauseEnabled = false;
    bool m_isNextEnabled = false;
    bool m_isPreviousEnabled = false;
};

#endif // MEDIAPLAYBACKMODEL_H
