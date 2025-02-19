/*
 * File: MediaPlaybackViewModel.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModel for MediaPlayback
 */

#ifndef MEDIAPLAYBACKVIEWMODEL_H
#define MEDIAPLAYBACKVIEWMODEL_H

#include <QObject>

class MediaPlaybackViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)
	Q_PROPERTY(bool isPlayingEnabled READ isPlayingEnabled WRITE setIsPlayingEnabled NOTIFY
	               isPlayingEnabledChanged)
	Q_PROPERTY(
	    bool isPauseEnabled READ isPauseEnabled WRITE setIsPauseEnabled NOTIFY isPauseEnabledChanged)
	Q_PROPERTY(
	    bool isNextEnabled READ isNextEnabled WRITE setIsNextEnabled NOTIFY isNextEnabledChanged)
	Q_PROPERTY(bool isPreviousEnabled READ isPreviousEnabled WRITE setIsPreviousEnabled NOTIFY
	               isPreviousEnabledChanged)

public:
	explicit MediaPlaybackViewModel(QObject *parent = nullptr);
	~MediaPlaybackViewModel();

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
	void isPlayingChanged();
	void isPlayingEnabledChanged();
	void isPauseEnabledChanged();
	void isNextEnabledChanged();
	void isPreviousEnabledChanged();

private:
	bool m_isPlaying = false;
	bool m_isPlayingEnabled = false;
	bool m_isPauseEnabled = false;
	bool m_isNextEnabled = false;
	bool m_isPreviousEnabled = false;
};

#endif // MEDIAPLAYBACKVIEWMODEL_H
