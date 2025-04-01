/*
 * File: MessageId.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Implementation for Service Message Id
 */

#ifndef SERVICE_MESSAGE_ID_H
#define SERVICE_MESSAGE_ID_H

#include <cstdint>

// TODO: remove this enum
enum class MessageId : uint16_t
{
	None = 0,
	WMediaInfoMessage = 1,
	WPlaybackControlsMessage = 2,
	WPlaybackInfoMessage = 3,
	WTimelinePropertiesMessage = 4,
	WPauseAsyncMessage = 5,
	WPlayAsyncMessage = 6,
	WNextAsyncMessage = 7,
	WPreviousAsyncMessage = 8,
};

#endif // SERVICE_MESSAGE_ID_H
