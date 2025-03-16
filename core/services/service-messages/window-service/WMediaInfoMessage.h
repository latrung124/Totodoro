/*
 * File: WMediaInfoMessage.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Media info message class
 */

#ifndef W_MEDIA_INFO_MESSAGE_H
#define W_MEDIA_INFO_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/ExtractStrategy.h"
#include <WMediaServiceUtils.h>

class WMediaInfoMessage : public ServiceMessage
{
public:
	using WMediaInfo = window_services::media::utils::WMediaInfo;
	using ExtractWMediaInfoStrategyUPtr = std::unique_ptr<ExtractStrategy<WMediaInfoMessage>>;

	WMediaInfoMessage(ExtractWMediaInfoStrategyUPtr strategy);
	~WMediaInfoMessage() = default;

	void setMediaInfo(const WMediaInfo &mediaInfo);
	WMediaInfo getMediaInfo() const;

	void extract() override;

private:
	WMediaInfo m_mediaInfo;
	ExtractWMediaInfoStrategyUPtr m_strategy;
};

#endif // W_MEDIA_INFO_MESSAGE_H
