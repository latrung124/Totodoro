/*
 * File: Context.h
 * Author: trung.la
 * Date: 02-23-2025
 * Description: This file contains the declaration of the Context class.
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>

class Context : public QObject
{
	Q_OBJECT

public:
	Context(QObject *obj = nullptr)
	    : QObject(obj)
	{
	}

	virtual ~Context() = default;
};
#endif // CONTEXT_H
