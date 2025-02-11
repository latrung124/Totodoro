/*
* File: Model.h
* Author: trung.la
* Date: 02-011-2025
* Description: Model class is base class for all models
*/

#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    Model(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Model() = default;
};

#endif // MODEL_H