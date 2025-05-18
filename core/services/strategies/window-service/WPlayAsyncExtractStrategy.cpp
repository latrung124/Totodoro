/*
 * File: WPlayAsyncExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WPlayAsyncExtractStrategy class.
 */

#include "core/services/strategies/window-service/WPlayAsyncExtractStrategy.h"

#include <QDebug>

#include <IWMediaService.h>

#include "core/services/messages/window-service/WPlayAsyncMessage.h"
#include "core/services/ServiceManager.h"

WPlayAsyncExtractStrategy::~WPlayAsyncExtractStrategy()
{
}

void WPlayAsyncExtractStrategy::execute(const WPlayAsyncMessage &message)
{
	extract(message);
}

void WPlayAsyncExtractStrategy::extract(const WPlayAsyncMessage &message)
{
	qDebug() << "WPlayAsyncExtractStrategy::extract()";
	auto service = ServiceManager::instance().getService<IWMediaService>();
	if (service != nullptr) {
		service->playAsync();
	} else {
		qDebug() << "WPlayAsyncExtractStrategy::extract() - Service not found";
	}
}
