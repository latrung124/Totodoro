/*
* File: MediaPlayerViewModel.h
* Author: trung.la
* Date: 02-05-2025
* Description: ViewModel for MediaPlayer
*/

#ifndef MEDIAPLAYERVIEWMODEL_H
#define MEDIAPLAYERVIEWMODEL_H

#include <QObject>
#include <QUrl>
#include <QString>

class MediaPlaybackViewModel;

class MediaPlayerViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(QObject *mediaPlaybackViewModel READ mediaPlaybackViewModel WRITE setMediaPlaybackViewModel NOTIFY mediaPlaybackViewModelChanged)
    Q_PROPERTY(QUrl thumbnail READ thumbnail WRITE setThumbnail NOTIFY thumbnailChanged)
public:
    explicit MediaPlayerViewModel(QObject *parent = nullptr);
    ~MediaPlayerViewModel();

    QString title() const;
    void setTitle(const QString &title);

    QString artist() const;
    void setArtist(const QString &artist);

    QObject *mediaPlaybackViewModel() const;
    void setMediaPlaybackViewModel(QObject *mediaPlaybackViewModel);

    QUrl thumbnail() const;
    void setThumbnail(const QUrl &thumbnail);

signals:
    void titleChanged();
    void artistChanged();
    void mediaPlaybackViewModelChanged();
    void thumbnailChanged();

private:
    QString m_title;
    QString m_artist;
    std::unique_ptr<MediaPlaybackViewModel> m_mediaPlaybackViewModel;
    QUrl m_thumbnail;
};

#endif // MEDIAPLAYERVIEWMODEL_H