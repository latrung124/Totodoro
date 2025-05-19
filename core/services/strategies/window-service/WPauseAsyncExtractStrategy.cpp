/*
 * File: WPauseAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPauseAsyncExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPauseAsyncExtractStrategy.h"

#include <QDebug>

#include <IWMediaService.h>

#include "core/services/ServiceManager.h"

#include "core/services/messages/window-service/WPauseAsyncMessage.h"

WPauseAsyncExtractStrategy::~WPauseAsyncExtractStrategy()
{
}

void WPauseAsyncExtractStrategy::execute(const WPauseAsyncMessage &message)
{
	extract(message);
}

void WPauseAsyncExtractStrategy::extract(const WPauseAsyncMessage &message)
{
	qDebug() << "WPauseAsyncExtractStrategy::extract()";
	auto service = ServiceManager::instance().getService<IWMediaService>();
	if (service != nullptr) {
		service->pauseAsync();
	} else {
		qDebug() << "WPauseAsyncExtractStrategy::extract() - Service not found";
	}
}
