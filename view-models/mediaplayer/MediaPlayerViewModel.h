/*
 * File: MediaPlayerViewModel.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: View Model for MediaPlayer
 */

#ifndef MEDIAPLAYERVIEWMODEL_H
#define MEDIAPLAYERVIEWMODEL_H

#include <QObject>
#include <QString>
#include <QUrl>

class MediaPlaybackViewModel;

class MediaPlayerViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString album READ album WRITE setAlbum NOTIFY albumChanged)
	Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
	Q_PROPERTY(QObject *mediaPlaybackViewModel READ mediaPlaybackViewModel WRITE
	               setMediaPlaybackViewModel NOTIFY mediaPlaybackViewModelChanged)
	Q_PROPERTY(QUrl thumbnail READ thumbnail WRITE setThumbnail NOTIFY thumbnailChanged)

public:
	explicit MediaPlayerViewModel(QObject *parent = nullptr);
	~MediaPlayerViewModel();

	QString title() const;
	void setTitle(const QString &title);

	QString album() const;
	void setAlbum(const QString &album);

	QString artist() const;
	void setArtist(const QString &artist);

	QObject *mediaPlaybackViewModel() const;
	void setMediaPlaybackViewModel(QObject *mediaPlaybackViewModel);

	QUrl thumbnail() const;
	void setThumbnail(const QUrl &thumbnail);

signals:
	void titleChanged();
	void albumChanged();
	void artistChanged();
	void mediaPlaybackViewModelChanged();
	void thumbnailChanged();

public slots:
	void onTitleChanged(const QString &title);
	void onAlbumChanged(const QString &album);
	void onArtistChanged(const QString &artist);
	void onThumbnailChanged(const QUrl &thumbnail);

private:
	void initDummyData();

	QString m_title;
	QString m_album;
	QString m_artist;
	QUrl m_thumbnail;
	std::unique_ptr<MediaPlaybackViewModel> m_mediaPlaybackViewModel;
};

#endif // MEDIAPLAYERVIEWMODEL_H
