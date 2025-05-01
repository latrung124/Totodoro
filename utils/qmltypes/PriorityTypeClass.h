/*
 * File: PriorityTypeClass.h
 * Author: trung.la
 * Date: 05-01-2025
 * Description: Class for PriorityType used for both qml and C++.
 */

#ifndef PRIORITYTYPECLASS_H
#define PRIORITYTYPECLASS_H

#include <QObject>

class PriorityTypeClass : public QObject
{
	Q_GADGET

public:
	enum class EPriorityType : uint16_t
	{
		Low = 0,
		Medium = 1,
		High = 2,
		Critical = 3
	};
	Q_ENUM(EPriorityType)

private:
	explicit PriorityTypeClass();
};

typedef PriorityTypeClass::EPriorityType PriorityType;

#endif // PRIORITYTYPECLASS_H
