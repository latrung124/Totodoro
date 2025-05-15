/*
 * File:  ViewModelController.h
 * Author: trung.la
 * Date: 02-05-2025
 * Description: ViewModelController class
 */

#ifndef VIEWMODELCONTROLLER_H
#define VIEWMODELCONTROLLER_H

#include <QObject>

#include <memory>
#include <typeindex>
#include <unordered_map>

#include "utils/qmltypes/MainTabTypeClass.h"

class MediaPlayerViewModel;
class HomeViewModel;
class ViewModelFactory;

class ViewModelController : public QObject
{
	Q_OBJECT

public:
	using ViewModelFactoryUPtr = std::unique_ptr<ViewModelFactory>;

	static ViewModelController &getInstance();

	~ViewModelController();

	void registerViewModels();

	void setRootObject(QObject *root);

	void initMediaPlayerView();
	void initHomeView();

	MediaPlayerViewModel *mediaPlayerViewModel();

	// INVOKEABLE FUNCTIONS
	Q_INVOKABLE void tabNavigation(MainTabType tabType);

private:
	ViewModelController(QObject *parent = nullptr);

	HomeViewModel *homeViewModel();

	ViewModelFactoryUPtr m_vmFactory;
	std::unordered_map<std::type_index, std::unique_ptr<QObject>> m_viewModels;
	QObject *m_rootObject = nullptr;
};

#endif // VIEWMODELCONTROLLER_H
