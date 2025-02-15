/*
* File: WMediaInfoMessage.h
* Author: trung.la
* Date: 02-09-2025
* Description: Media info message class
*/

#ifndef W_MEDIA_INFO_MESSAGE_H
#define W_MEDIA_INFO_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "interfaces/window-services/WMediaServiceUtils.h"

class WMediaInfoMessage : public ServiceMessage
{
public:
    using WMediaInfo = window_services::media::utils::WMediaInfo;

    WMediaInfoMessage();
    ~WMediaInfoMessage() = default;

    void setMediaInfo(const WMediaInfo& mediaInfo);
    WMediaInfo getMediaInfo() const;

private:
    WMediaInfo m_mediaInfo;
};

#endif // W_MEDIA_INFO_MESSAGE_H