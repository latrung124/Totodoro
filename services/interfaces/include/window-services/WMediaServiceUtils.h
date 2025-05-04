/*
 * File: WMediaServiceUtils.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Utility functions for media service
 */

#ifndef W_MEDIA_SERVICE_UTILS_H
#define W_MEDIA_SERVICE_UTILS_H

#include <chrono>
#include <stdint.h>
#include <string>
#include <vector>

namespace window_services { namespace media { namespace utils {

enum class WMediaPlaybackType : uint16_t
{
	Unknown = 0,
	Music = 1,
	Video = 2,
	Image = 3
};

enum class WMediaPlaybackAutoRepeatMode : uint16_t
{
	None = 0,
	Track = 1,
	List = 2
};

enum WMediaPlaybackStatus : uint16_t
{
	Closed = 0,
	Opened = 1,
	Changing = 2,
	Stopped = 3,
	Playing = 4,
	Paused = 5
};

struct WMediaInfo
{
	std::string albumTitle = "";
	std::string albumArtist = "";
	int32_t totalTracks = 0;
	std::string artist = "";
	std::vector<std::string> genres = {};
	WMediaPlaybackType playbackType = WMediaPlaybackType::Unknown;
	std::string subtitle = "";
	std::string thumbnail = "";
	std::string title = "";
	int32_t trackNumber = 0;
};

struct WPlaybackControls
{
	bool isChannelDownEnabled = false;
	bool isChannelUpEnabled = false;
	bool isFastForwardEnabled = false;
	bool isNextEnabled = false;
	bool isPauseEnabled = false;
	bool isPlaybackPositionEnabled = false;
	bool isPlaybackRateEnabled = false;
	bool isPlayEnabled = false;
	bool isPlayPauseToggleEnabled = false;
	bool isPreviousEnabled = false;
	bool isRecordEnabled = false;
	bool isRepeatEnabled = false;
	bool isRewindEnabled = false;
	bool isShuffleEnabled = false;
	bool isStopEnabled = false;
};

struct WPlaybackInfo
{
	WMediaPlaybackAutoRepeatMode autoRepeatMode = WMediaPlaybackAutoRepeatMode::None;
	WPlaybackControls playbackControls = {};
	bool isShuffled = false;
	double playbackRate = 0.0;
	WMediaPlaybackStatus playbackStatus = WMediaPlaybackStatus::Closed;
	WMediaPlaybackType playbackType = WMediaPlaybackType::Unknown;
};

struct WTimelineProperties
{
	int64_t endTime = 0;
	int64_t startTime = 0;
	std::chrono::system_clock::time_point lastUpdatedTime;
	int64_t maxSeekTime = 0;
	int64_t minSeekTime = 0;
	int64_t position = 0;
};
}}} // namespace window_services::media::utils

#endif // W_MEDIA_SERVICE_UTILS_H
