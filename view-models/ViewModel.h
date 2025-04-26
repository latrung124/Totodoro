/*
* File: ViewModel.h
* Author: trung.la
* Date: 04-26-2025
* Description: ViewModel class definition
* This class serves as a base class for all ViewModel classes in the application.
*/

#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>

class ViewModel : public QObject
{
    Q_OBJECT
public:
    explicit ViewModel(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~ViewModel() = default; 
};

#endif // VIEWMODEL_H