/*
 * File: WMediaInfoExtractStrategy.cpp
 * Author: trung.la
 * Date: 03-16-2025
 * Description: This file contains the implementation of the WMediaInfoExtractStrategy class.
 */

#include "core/services/strategies/window-service/WMediaInfoExtractStrategy.h"

#include <QDebug>

#include "core/controllers/ModelController.h"

#include "core/services/messages/window-service/WMediaInfoMessage.h"

WMediaInfoExtractStrategy::~WMediaInfoExtractStrategy()
{
}

void WMediaInfoExtractStrategy::execute(const WMediaInfoMessage &message)
{
	extract(message);
}

void WMediaInfoExtractStrategy::extract(const WMediaInfoMessage &message)
{
	qDebug() << "WMediaInfoExtractStrategy::extract";
	// TODO: emit signal to update model from worker thread
}
