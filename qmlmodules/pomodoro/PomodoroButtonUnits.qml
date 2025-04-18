/*
* File: PomodoroButtonUnits.qml
* Author: trung.la
* Date: 04-14-2025
* Description: PomodoroButtonUnits.qml is a QML file that defines states of Pomodoro button.
*/

import QtQuick

QtObject {
    id: root

    enum PomodoroButtonState {
        Start,
        Pause,
        Resume
    }
}
