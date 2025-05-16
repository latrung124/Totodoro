/*
 * File: MediaPlaybackModel.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: This file contains the declaration of the MediaPlaybackModel class.
 */

#ifndef MEDIAPLAYBACKMODEL_H
#define MEDIAPLAYBACKMODEL_H

#include "models/SystemDataModel.h"

#include <mutex>

class MediaPlaybackModel
{
public:
	MediaPlaybackModel();
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

private:
	mutable std::mutex m_mutex;
	bool m_isPlaying = false;
	bool m_isPlayingEnabled = false;
	bool m_isPauseEnabled = false;
	bool m_isNextEnabled = false;
	bool m_isPreviousEnabled = false;
};

#endif // MEDIAPLAYBACKMODEL_H
