/*
 * File: WMediaInfoMessage.cpp
 * Author: trung.la
 * Date: 02-09-2025
 * Description: Media info message class
 */

#include "WMediaInfoMessage.h"

namespace {
using namespace window_services::media::utils;
}

WMediaInfoMessage::WMediaInfoMessage(ExtractWMediaInfoStrategyUPtr strategy)
    : Message(MessageId::WMediaInfoMessage)
    , m_strategy(std::move(strategy))
{
}

void WMediaInfoMessage::setMediaInfo(const WMediaInfo &mediaInfo)
{
	m_mediaInfo = mediaInfo;
}

WMediaInfo WMediaInfoMessage::getMediaInfo() const
{
	return m_mediaInfo;
}

void WMediaInfoMessage::execute()
{
	m_strategy->execute(*this);
}
