/*
 * File: ViewModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModelController class
 */

#include "ViewModelController.h"

#include <QVariant>

#include "view-models/mediaplayer/MediaPlayerViewModel.h"

#include "core/factories/view-model-producers/MediaPlayerVMProducer.h"

#include "core/factories/ViewModelFactory.h"

ViewModelController::ViewModelController(QObject *parent)
    : QObject(parent)
    , m_vmFactory(std::make_unique<ViewModelFactory>())
{
}

ViewModelController::~ViewModelController()
{
}

void ViewModelController::registerViewModels()
{
	m_vmFactory->registerViewModel<MediaPlayerVMProducer>();
}

MediaPlayerViewModel *ViewModelController::mediaPlayerViewModel()
{
	std::type_index typeIndex = std::type_index(typeid(MediaPlayerViewModel));
	auto it = m_viewModels.find(typeIndex);
	if (it == m_viewModels.end()) {
		auto mediaPlayerVM = m_vmFactory->createViewModel<MediaPlayerVMProducer>();
		if (mediaPlayerVM) {
			m_viewModels[typeIndex] = std::move(mediaPlayerVM);
			it = m_viewModels.find(typeIndex); // Update the iterator after insertion
		}
	}

	// Ensure the iterator is valid before dereferencing
	if (it != m_viewModels.end() && !it->second) {
		m_viewModels[typeIndex] = m_vmFactory->createViewModel<MediaPlayerVMProducer>();
		it = m_viewModels.find(typeIndex); // Update the iterator again
	}

	return dynamic_cast<MediaPlayerViewModel *>(it->second.get());
}

void ViewModelController::initMediaPlayerView(QObject *obj)
{
	if (!obj) {
		return;
	}

	auto mediaPlayerVM = mediaPlayerViewModel();
	auto mediaView = obj->findChild<QObject *>(
	    "mediaPlayer"); // find QtObject with objectName property
	if (mediaPlayerVM && mediaView) {
		mediaView->setProperty("model", QVariant::fromValue(mediaPlayerVM));
	}
}
