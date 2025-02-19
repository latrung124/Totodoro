/*
 * File: DatabaseModel.h
 * Author: trung.la
 * Date: 02-11-2025
 * Description: DatabaseModel class is base class for all database models
 */

#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include "models/Model.h"

class DatabaseModel : public Model
{
public:
	DatabaseModel();
	virtual ~DatabaseModel();
};

#endif // DATABASEMODEL_H
