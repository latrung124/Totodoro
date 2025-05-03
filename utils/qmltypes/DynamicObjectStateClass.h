/*
 * File: DynamicObjectStateClass.h
 * Author: trung.la
 * Date: 05-03-2025
 * Description: Class for DynamicObjectState used for both qml and C++.
 */

#ifndef DYNAMICOBJECTSTATECLASS_H
#define DYNAMICOBJECTSTATECLASS_H

#include <QObject>

class DynamicObjectStateClass : public QObject
{
	Q_GADGET

public:
	enum class EDynamicObjectState : uint16_t
	{
		Egg = 0,
		Little = 1,
		Medium = 2,
		Final = 3,
	};
	Q_ENUM(EDynamicObjectState)

private:
	explicit DynamicObjectStateClass();
};

typedef DynamicObjectStateClass::EDynamicObjectState DynamicObjectState;

#endif // DYNAMICOBJECTSTATECLASS_H
