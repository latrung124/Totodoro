/*
 * File: WindowSystemMedia.cpp
 * Author: trung.la
 * Date: 02-22-2025
 * Description: This file contains the implementation of the WindowSystemMedia class.
 */

#include "WindowSystemMedia.h"

#include "WindowMediaService.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Streams.h>

namespace {

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Media::Control;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace window_services::media::utils;

static WMediaPlaybackType convertPlaybackType(
    Windows::Foundation::IReference<Windows::Media::MediaPlaybackType> playbackType)
{
	if (playbackType == nullptr) {
		return WMediaPlaybackType::Unknown;
	}

	switch (playbackType.Value()) {
	case Windows::Media::MediaPlaybackType::Music:
		return WMediaPlaybackType::Music;
	case Windows::Media::MediaPlaybackType::Video:
		return WMediaPlaybackType::Video;
	case Windows::Media::MediaPlaybackType::Image:
		return WMediaPlaybackType::Image;
	default:
		return WMediaPlaybackType::Unknown;
	}
}

int generateRandom7DigitNumber()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1000000, 9999999); // Range for a 7-digit number

	return dist(gen);
}

std::string saveThumbnailToFile(
    const GlobalSystemMediaTransportControlsSessionMediaProperties &mediaProperties)
{
	try {
		auto thumbnailReference = mediaProperties.Thumbnail();
		if (!thumbnailReference) {
			std::wcerr << L"No thumbnail available." << std::endl;
			return "";
		}

		auto stream = thumbnailReference.OpenReadAsync().get();
		if (!stream) {
			std::wcerr << L"Failed to open thumbnail stream." << std::endl;
			return "";
		}

		auto temporaryFileName = std::to_string(generateRandom7DigitNumber()) + "_thumbnail.jpg";
		std::filesystem::path outputPath =
		    std::filesystem::temp_directory_path() / temporaryFileName;

		auto size = static_cast<size_t>(stream.Size());
		std::vector<uint8_t> buffer(size);

		auto reader = DataReader(stream);
		reader.LoadAsync(static_cast<uint32_t>(size)).get();
		reader.ReadBytes(buffer);

		std::ofstream outputFile(outputPath, std::ios::binary);
		if (outputFile.is_open()) {
			outputFile.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
			outputFile.close();
			std::cout << "Thumbnail saved to: " << outputPath.string() << std::endl;
			return outputPath.string();
		} else {
			std::wcerr << L"Failed to open output file." << std::endl;
			return "";
		}
	} catch (const hresult_error &ex) {
		std::wcerr << L"Error: " << ex.message().c_str() << std::endl;
		return "";
	}
}

std::chrono::system_clock::time_point convertDateTimeToChrono(DateTime winrtTime)
{
	// Duration since January 1, 1601 (UTC) in 100-nanosecond units
	auto duration100ns = std::chrono::duration<int64_t, std::ratio<1, 10'000'000>>(
	    winrtTime.time_since_epoch().count());

	// Windows epoch start (January 1, 1601) as a chrono time_point
	constexpr std::chrono::system_clock::time_point windowsEpoch =
	    std::chrono::system_clock::time_point(
	        std::chrono::duration<int64_t>(11644473600)); // seconds from 1601 to 1970

	// Convert to standard system_clock time_point
	return windowsEpoch + duration100ns;
}

} // namespace

WindowSystemMedia::WindowSystemMedia(WindowMediaService *service)
    : m_service(service)
{
	std::thread init(&WindowSystemMedia::systemInit, this);
	init.detach();
}

WindowSystemMedia::~WindowSystemMedia()
{
}

bool WindowSystemMedia::systemInit()
{
	try {
		IAsyncOperation<GlobalSystemMediaTransportControlsSessionManager> sessionManagerRes =
		    GlobalSystemMediaTransportControlsSessionManager::RequestAsync();
		m_sessionManager = sessionManagerRes.get();
		if (!m_sessionManager) {
			return false;
		}
		registerCurrentSessionChangedEvents();

		m_session = m_sessionManager.GetCurrentSession();
		if (m_session) {
			registerSessionPropertiesChangedEvents();
			getSyncMediaProperties(m_session);
		}
	} catch (const winrt::hresult_error &ex) {
		winrt::hstring message = ex.message();
		throw std::runtime_error(winrt::to_string(message));
	} catch (...) {
		throw std::runtime_error("Unknown error");
	}

	return true;
}

template<>
void WindowSystemMedia::updateMediaProperties(
    GlobalSystemMediaTransportControlsSessionMediaProperties &&properties)
{
	removeOldTempThumbnail();

	WMediaInfo mediaInfo{
	    .albumTitle = winrt::to_string(properties.AlbumTitle()),
	    .albumArtist = winrt::to_string(properties.AlbumArtist()),
	    .totalTracks = properties.AlbumTrackCount(),
	    .artist = winrt::to_string(properties.AlbumArtist()),
	    .genres = {}, // TODO: handle genres data
	    .playbackType = convertPlaybackType(properties.PlaybackType()),
	    .subtitle = winrt::to_string(properties.Subtitle()),
	    .thumbnail = saveThumbnailToFile(properties),
	    .title = winrt::to_string(properties.Title()),
	    .trackNumber = properties.TrackNumber(),
	};
	m_thumbnailPath = mediaInfo.thumbnail;
	m_service->systemMediaPropertiesChanged(mediaInfo);
}

template<>
void WindowSystemMedia::updateMediaProperties(
    GlobalSystemMediaTransportControlsSessionPlaybackInfo &&playbackInfo)
{
	if (!m_service) {
		return;
	}

	auto playbackControls = playbackInfo.Controls();
	auto playbackStatus = playbackInfo.PlaybackStatus();
	auto playbackType = playbackInfo.PlaybackType();
	auto repeatMode = playbackInfo.AutoRepeatMode();

	if (!playbackControls) {
		return;
	}

	WPlaybackControls wPlaybackControls{
	    .isChannelDownEnabled = playbackControls.IsChannelDownEnabled(),
	    .isChannelUpEnabled = playbackControls.IsChannelUpEnabled(),
	    .isFastForwardEnabled = playbackControls.IsFastForwardEnabled(),
	    .isNextEnabled = playbackControls.IsNextEnabled(),
	    .isPauseEnabled = playbackControls.IsPauseEnabled(),
	    .isPlaybackPositionEnabled = playbackControls.IsPlaybackPositionEnabled(),
	    .isPlaybackRateEnabled = playbackControls.IsPlaybackRateEnabled(),
	    .isPlayEnabled = playbackControls.IsPlayEnabled(),
	    .isPlayPauseToggleEnabled = playbackControls.IsPlayPauseToggleEnabled(),
	    .isPreviousEnabled = playbackControls.IsPreviousEnabled(),
	    .isRecordEnabled = playbackControls.IsRecordEnabled(),
	    .isRepeatEnabled = playbackControls.IsRepeatEnabled(),
	    .isRewindEnabled = playbackControls.IsRewindEnabled(),
	    .isShuffleEnabled = playbackControls.IsShuffleEnabled(),
	    .isStopEnabled = playbackControls.IsStopEnabled(),
	};

	m_service->systemPlaybackControlsChanged(wPlaybackControls);

	WMediaPlaybackAutoRepeatMode wRepeatMode =
	    repeatMode == nullptr
	        ? WMediaPlaybackAutoRepeatMode::None
	        : static_cast<WMediaPlaybackAutoRepeatMode>(repeatMode.Value());
	WMediaPlaybackStatus wPlaybackStatus = static_cast<WMediaPlaybackStatus>(playbackStatus);
	WMediaPlaybackType wPlaybackType = convertPlaybackType(playbackType);

	bool isShuffled = false;
	if (playbackInfo.IsShuffleActive()) {
		isShuffled = playbackInfo.IsShuffleActive().Value();
	}
	double playbackRate = 0.0;
	if (playbackInfo.PlaybackRate()) {
		playbackRate = playbackInfo.PlaybackRate().Value();
	}
	WPlaybackInfo wPlaybackInfo{
	    .autoRepeatMode = wRepeatMode,
	    .playbackControls = wPlaybackControls,
	    .isShuffled = isShuffled,
	    .playbackRate = playbackRate,
	    .playbackStatus = wPlaybackStatus,
	    .playbackType = wPlaybackType,
	};

	m_service->systemPlaybackInfoChanged(wPlaybackInfo);
}

template<>
void WindowSystemMedia::updateMediaProperties(
    GlobalSystemMediaTransportControlsSessionTimelineProperties &&properties)
{
	WTimelineProperties wTimelineProperties{
	    .endTime = properties.EndTime().count(),
	    .startTime = properties.StartTime().count(),
	    .lastUpdatedTime = convertDateTimeToChrono(properties.LastUpdatedTime()),
	    .maxSeekTime = properties.MaxSeekTime().count(),
	    .minSeekTime = properties.MinSeekTime().count(),
	    .position = properties.Position().count(),
	};

	m_service->systemTimelinePropertiesChanged(wTimelineProperties);
}

void WindowSystemMedia::registerCurrentSessionChangedEvents()
{
	if (m_sessionManager) {
		m_sessionManager.CurrentSessionChanged(
		    [this](
		        GlobalSystemMediaTransportControlsSessionManager manager,
		        CurrentSessionChangedEventArgs args) { registerSessionPropertiesChangedEvents(); });
	}
}

void WindowSystemMedia::registerSessionPropertiesChangedEvents()
{
	if (!m_session) {
		return;
	}

	m_session.MediaPropertiesChanged(
	    [this](
	        GlobalSystemMediaTransportControlsSession session,
	        MediaPropertiesChangedEventArgs args) {
		    // TODO: handle media properties changed
		    const auto mediaPropertiesAsync = session.TryGetMediaPropertiesAsync();
		    if (!mediaPropertiesAsync) {
			    return;
		    }
		    updateMediaProperties(std::move(mediaPropertiesAsync.get()));
	    });

	m_session.PlaybackInfoChanged(
	    [this](
	        GlobalSystemMediaTransportControlsSession session, PlaybackInfoChangedEventArgs args) {
		    if (!session) {
			    return;
		    }
		    updateMediaProperties(std::move(session.GetPlaybackInfo()));
	    });

	m_session.TimelinePropertiesChanged(
	    [this](
	        GlobalSystemMediaTransportControlsSession session,
	        TimelinePropertiesChangedEventArgs args) {
		    if (!session) {
			    return;
		    }

		    auto timelineProperties = session.GetTimelineProperties();
		    if (!timelineProperties) {
			    return;
		    }

		    updateMediaProperties(std::move(timelineProperties));
	    });
}

void WindowSystemMedia::removeOldTempThumbnail()
{
	if (!m_thumbnailPath.empty()) {
		std::filesystem::remove(m_thumbnailPath);
	}
}

void WindowSystemMedia::getSyncMediaProperties(
    const GlobalSystemMediaTransportControlsSession &session)
{
	const auto mediaPropertiesAsync = session.TryGetMediaPropertiesAsync();
	if (!mediaPropertiesAsync) {
		std::cerr << "Failed to get media properties." << std::endl;
		return;
	}
	updateMediaProperties(std::move(mediaPropertiesAsync.get()));

	updateMediaProperties(std::move(session.GetPlaybackInfo()));

	auto timelineProperties = session.GetTimelineProperties();
	if (!timelineProperties) {
		std::cerr << "Failed to get timeline properties." << std::endl;
		return;
	}

	updateMediaProperties(std::move(timelineProperties));
}

WindowSystemMedia::IAsyncOperationBool WindowSystemMedia::tryPlayAsync()
try {
	if (m_session) {
		bool tResult = co_await m_session.TryPlayAsync();
		co_return tResult;
	}

	co_return false;
} catch (const winrt::hresult_error &ex) {
	// Handle any exceptions
	std::wcout << L"Error trying to play media: " << ex.message().c_str() << std::endl;
	co_return false;
}

WindowSystemMedia::IAsyncOperationBool WindowSystemMedia::tryPauseAsync()
try {
	if (m_session) {
		bool tResult = co_await m_session.TryPauseAsync();
		co_return tResult;
	}

	co_return false;
} catch (const winrt::hresult_error &ex) {
	// Handle any exceptions
	std::wcout << L"Error trying to play media: " << ex.message().c_str() << std::endl;
	co_return false;
}

WindowSystemMedia::IAsyncOperationBool WindowSystemMedia::tryNextAsync()
try {
	if (m_session) {
		bool tResult = co_await m_session.TrySkipNextAsync();
		co_return tResult;
	}

	co_return false;
} catch (const winrt::hresult_error &ex) {
	// Handle any exceptions
	std::wcout << L"Error trying to play media: " << ex.message().c_str() << std::endl;
	co_return false;
}

WindowSystemMedia::IAsyncOperationBool WindowSystemMedia::tryPreviousAsync()
try {
	if (m_session) {
		bool tResult = co_await m_session.TrySkipPreviousAsync();
		co_return tResult;
	}

	co_return false;
} catch (const winrt::hresult_error &ex) {
	// Handle any exceptions
	std::wcout << L"Error trying to play media: " << ex.message().c_str() << std::endl;
	co_return false;
}
