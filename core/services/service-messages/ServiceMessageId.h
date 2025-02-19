/*
 * File: ServiceMessageId.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Implementation for Service Message Id
 */

#ifndef SERVICE_MESSAGE_ID_H
#define SERVICE_MESSAGE_ID_H

#include <cstdint>

enum class ServiceMessageId : uint16_t
{
	None = 0,
	WMediaInfoMessage = 1,
	WPlaybackControlsMessage = 2,
	WPlaybackInfoMessage = 3,
};

#endif // SERVICE_MESSAGE_ID_H
