/*
* File:  ViewModelController.h
* Author: trung.la
* Date: 02-05-2025
* Description: ViewModelController class
*/

#ifndef VIEWMODELCONTROLLER_H
#define VIEWMODELCONTROLLER_H

#include <memory>

#include <QObject>

class MediaPlayerViewModel;

class ViewModelController : public QObject
{
    Q_OBJECT

public:
    using MediaPlayerViewModelPtr = std::shared_ptr<MediaPlayerViewModel>;
    using MediaPlayerViewModelWPtr = std::weak_ptr<MediaPlayerViewModel>;
    
    ViewModelController(QObject *parent = nullptr);
    ~ViewModelController();

    MediaPlayerViewModelWPtr getMediaPlayerViewModel() const;

private:
    MediaPlayerViewModelPtr m_mediaPlayerViewModel;
};

#endif // VIEWMODELCONTROLLER_H