/*
 * File: MediaPlaybackViewModel.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: View Model for MediaPlayback
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
	Q_PROPERTY(bool isShuffleEnabled READ isShuffleEnabled WRITE setIsShuffleEnabled NOTIFY
	               isShuffleEnabledChanged)
	Q_PROPERTY(bool isRepeatEnabled READ isShuffleEnabled WRITE setIsShuffleEnabled NOTIFY
	               isShuffleEnabledChanged)

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

	bool isShuffleEnabled() const;
	void setIsShuffleEnabled(bool isShuffleEnabled);

	bool isRepeatEnabled() const;
	void setIsRepeatEnabled(bool isRepeatEnabled);

signals:
	void isPlayingChanged();
	void isPlayingEnabledChanged();
	void isPauseEnabledChanged();
	void isNextEnabledChanged();
	void isPreviousEnabledChanged();
	void isShuffleEnabledChanged();
	void isRepeatEnabledChanged();

public slots:
	void play();
	void pause();
	void next();
	void previous();
	void shuffle();
	void repeat();

	void onIsPlayingChanged(bool isPlaying);
	void onIsPlayingEnabledChanged(bool isPlayingEnabled);
	void onIsPauseEnabledChanged(bool isPauseEnabled);
	void onIsNextEnabledChanged(bool isNextEnabled);
	void onIsPreviousEnabledChanged(bool isPreviousEnabled);

private:
	void initDummyData();

	bool m_isPlaying = false;
	bool m_isPlayingEnabled = false;
	bool m_isPauseEnabled = false;
	bool m_isNextEnabled = false;
	bool m_isPreviousEnabled = false;
	bool m_isShuffleEnabled = false;
	bool m_isRepeatEnabled = false;
};

#endif // MEDIAPLAYBACKVIEWMODEL_H
