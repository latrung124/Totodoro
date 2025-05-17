/*
 * File: ViewModelController.cpp
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModelController class
 */

#include "ViewModelController.h"

#include <QDebug>
#include <QVariant>

#include "core/factories/view-model-producers/HomeVMProducer.h"
#include "core/factories/view-model-producers/MediaPlayerVMProducer.h"

#include "core/factories/ViewModelFactory.h"

#include "core/controllers/ModelController.h"

#include "view-models/home/HomeViewModel.h"
#include "view-models/mediaplayer/MediaPlayerViewModel.h"

ViewModelController &ViewModelController::getInstance()
{
	static ViewModelController instance;
	return instance;
}

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
	m_vmFactory->registerViewModel<HomeVMProducer>();
}

void ViewModelController::setRootObject(QObject *root)
{
	if (root) {
		m_rootObject = root;
	} else {
		qDebug() << "ViewModelController::rootObjectChanged: Invalid object passed";
	}
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

HomeViewModel *ViewModelController::homeViewModel()
{
	std::type_index typeIndex = std::type_index(typeid(HomeViewModel));
	auto it = m_viewModels.find(typeIndex);
	if (it == m_viewModels.end()) {
		auto homeVM = m_vmFactory->createViewModel<HomeVMProducer>();
		if (homeVM) {
			m_viewModels[typeIndex] = std::move(homeVM);
			it = m_viewModels.find(typeIndex); // Update the iterator after insertion
		}
	}

	// Ensure the iterator is valid before dereferencing
	if (it != m_viewModels.end() && !it->second) {
		m_viewModels[typeIndex] = m_vmFactory->createViewModel<HomeVMProducer>();
		it = m_viewModels.find(typeIndex); // Update the iterator again
	}

	return dynamic_cast<HomeViewModel *>(it->second.get());
}

void ViewModelController::initMediaPlayerView()
{
	if (!m_rootObject) {
		qDebug() << "ViewModelController::initMediaPlayerView: Invalid root object";
		return;
	}

	auto obj = m_rootObject->findChild<QObject *>(
	    "mediaPlayer"); // find QtObject with objectName property

	if (!obj) {
		qDebug() << "Can't find media player view object!";
		return;
	}

	auto mediaPlayerVM = mediaPlayerViewModel();
	auto mediaPlayerModel = ModelController::getInstance().getMediaPlayerModel();
	if (auto mediaPlayerModelPtr = mediaPlayerModel.lock(); mediaPlayerModelPtr && mediaPlayerVM) {
		mediaPlayerVM->updateMediaPlayerFromModel(*mediaPlayerModelPtr);
	}

	obj->setProperty("model", QVariant::fromValue(mediaPlayerVM));
}

void ViewModelController::initHomeView()
{
	if (!m_rootObject) {
		qDebug() << "ViewModelController::initHomeView: Invalid root object";
		return;
	}

	auto obj = m_rootObject->findChild<QObject *>(
	    "homeView"); // find QtObject with objectName property

	if (!obj) {
		qDebug() << "ViewModelController::initHomeView: Invalid object passed";
		return;
	}

	auto homeVM = homeViewModel();
	if (homeVM) {
		obj->setProperty("model", QVariant::fromValue(homeVM));
	}
}

void ViewModelController::tabNavigation(MainTabType tabType)
{
	// TODO: implement remove old view model to improve memory usage
	switch (tabType) {
	case MainTabType::Home:
		initHomeView();
		break;
	case MainTabType::Statistic:
		// TODO: Implement initStatisticView() function
		break;
	default:
		break;
	}
}
