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

class MediaPlayerViewModel;
class ViewModelFactory;

class ViewModelController : public QObject
{
	Q_OBJECT

public:
	using ViewModelFactoryUPtr = std::unique_ptr<ViewModelFactory>;

	ViewModelController(QObject *parent = nullptr);
	~ViewModelController();

	void registerViewModels();

	void initMediaPlayerView(QObject *obj);

private:
	MediaPlayerViewModel *mediaPlayerViewModel();

	ViewModelFactoryUPtr m_vmFactory;
	std::unordered_map<std::type_index, std::unique_ptr<QObject>> m_viewModels;
};

#endif // VIEWMODELCONTROLLER_H
