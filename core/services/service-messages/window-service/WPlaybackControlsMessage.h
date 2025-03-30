/*
 * File: WPlaybackControlsMessage.h
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Playback controls message class
 */

#ifndef W_PLAYBACK_CONTROLS_MESSAGE_H
#define W_PLAYBACK_CONTROLS_MESSAGE_H

#include "core/services/service-messages/ServiceMessage.h"
#include "core/services/service-strategies/IStrategy.h"
#include <WMediaServiceUtils.h>

class WPlaybackControlsMessage : public ServiceMessage
{
public:
	using WPlaybackControls = window_services::media::utils::WPlaybackControls;
	using ExtractWPlaybackControlsStrategyUPtr =
	    std::unique_ptr<IStrategy<WPlaybackControlsMessage>>;

	WPlaybackControlsMessage(ExtractWPlaybackControlsStrategyUPtr strategy);
	~WPlaybackControlsMessage() = default;

	void setWPlaybackControls(const WPlaybackControls &wPlaybackControls);
	WPlaybackControls getWPlaybackControls() const;

	void extract() override;

private:
	WPlaybackControls m_wPlaybackControls;
	ExtractWPlaybackControlsStrategyUPtr m_strategy;
};

#endif // W_PLAYBACK_CONTROLS_MESSAGE_H
