/*
 * File: WPlaybackInfoMessage.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Playback info message class
 */

#ifndef W_PLAYBACK_INFO_MESSAGE_H
#define W_PLAYBACK_INFO_MESSAGE_H

#include "core/services/messages/Message.h"
#include "core/services/strategies/IStrategy.h"
#include <WMediaServiceUtils.h>

class WPlaybackInfoMessage : public Message
{
public:
	using WPlaybackInfo = window_services::media::utils::WPlaybackInfo;
	using ExtractWPlaybackInfoStrategyUPtr = std::unique_ptr<IStrategy<WPlaybackInfoMessage>>;

	WPlaybackInfoMessage(ExtractWPlaybackInfoStrategyUPtr strategy);
	~WPlaybackInfoMessage() = default;

	void setWPlaybackInfo(const WPlaybackInfo &wPlaybackInfo);
	WPlaybackInfo getWPlaybackInfo() const;

	void execute() override;

private:
	WPlaybackInfo m_wPlaybackInfo;
	ExtractWPlaybackInfoStrategyUPtr m_strategy;
};

#endif // W_PLAYBACK_INFO_MESSAGE_H
