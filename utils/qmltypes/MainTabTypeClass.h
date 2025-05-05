/*
 * File: MainTabTypeClass.h
 * Author: trung.la
 * Date: 05-05-2025
 * Description: Class for MainTabType used for both qml and C++.
 */

#ifndef MAINTABTYPECLASS_H
#define MAINTABTYPECLASS_H

#include <QObject>

class MainTabTypeClass : public QObject
{
	Q_GADGET

public:
	enum class EMainTabType : uint16_t
	{
		Home = 0,
		Statistic = 1,
	};
	Q_ENUM(EMainTabType)

private:
	explicit MainTabTypeClass();
};

typedef MainTabTypeClass::EMainTabType MainTabType;

#endif // PRIORITYTYPECLASS_H
