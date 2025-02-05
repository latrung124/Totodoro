/*
* File: MediaPlayerModel.h
* Author: trung.la
* Date: 02-05-2025
* Description: This file contains the declaration of the MediaPlayerModel class.
*/

#ifndef MEDIAPLAYERMODEL_H
#define MEDIAPLAYERMODEL_H

#include <memory>

#include <QObject>
#include <QString>
#include <QUrl>

class MediaPlaybackModel;

class MediaPlayerModel : public QObject
{
    Q_OBJECT

public:
    using MediaPlaybackModelPtr = std::shared_ptr<MediaPlaybackModel>;

    explicit MediaPlayerModel(QObject *parent = nullptr);
    ~MediaPlayerModel() = default;

    QString title() const;
    void setTitle(const QString &title);

    QString artist() const;
    void setArtist(const QString &artist);

    QUrl thumbnail() const;
    void setThumbnail(const QUrl &thumbnail);

    MediaPlaybackModelPtr mediaPlaybackModel() const;

signals:
    void titleChanged(const QString &title);
    void artistChanged(const QString &artist);
    void thumbnailChanged(const QUrl &thumbnail);

private:
    QString m_title;
    QString m_artist;
    QUrl m_thumbnail;
    MediaPlaybackModelPtr m_mediaPlaybackModel;
};

#endif // MEDIAPLAYERMODEL_H