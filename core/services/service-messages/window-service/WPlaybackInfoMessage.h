/*
 * File: WPlaybackInfoMessage.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Playback info message class
 */

#ifndef W_PLAYBACK_INFO_MESSAGE_H
#define W_PLAYBACK_INFO_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/ExtractStrategy.h"
#include <WMediaServiceUtils.h>

class WPlaybackInfoMessage : public ServiceMessage
{
public:
	using WPlaybackInfo = window_services::media::utils::WPlaybackInfo;
	using ExtractWPlaybackInfoStrategyUPtr = std::unique_ptr<ExtractStrategy<WPlaybackInfoMessage>>;

	WPlaybackInfoMessage(ExtractWPlaybackInfoStrategyUPtr strategy);
	~WPlaybackInfoMessage() = default;

	void setWPlaybackInfo(const WPlaybackInfo &wPlaybackInfo);
	WPlaybackInfo getWPlaybackInfo() const;

	void extract() override;

private:
	WPlaybackInfo m_wPlaybackInfo;
	ExtractWPlaybackInfoStrategyUPtr m_strategy;
};

#endif // W_PLAYBACK_INFO_MESSAGE_H
