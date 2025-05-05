/*
 * File: PomodoroStateClass.h
 * Author: trung.la
 * Date: 06-05-2025
 * Description: Class for PomodoroState used for both qml and C++.
 */

#ifndef POMODOROSTATECLASS_H
#define POMODOROSTATECLASS_H

#include <QObject>

class PomodoroStateClass : public QObject
{
	Q_GADGET

public:
	enum class EPomodoroState : uint16_t
	{
		Idle = 0,
		Running = 1,
		Pause = 2
	};
	Q_ENUM(EPomodoroState)

private:
	explicit PomodoroStateClass();
};

typedef PomodoroStateClass::EPomodoroState PomodoroState;

#endif // POMODOROSTATECLASS_H
