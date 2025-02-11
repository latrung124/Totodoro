/*
* File: SystemDataModel.h
* Author: trung.la
* Date: 02-11-2025
* Description: SystemDataModel class is base class for all system data models
*/

#ifndef SYSTEMDATAMODEL_H
#define SYSTEMDATAMODEL_H

#include "models/Model.h"

class SystemDataModel : public Model
{
public:
    SystemDataModel(QObject *parent = nullptr);
    virtual ~SystemDataModel();
};

#endif // SYSTEMDATAMODEL_H