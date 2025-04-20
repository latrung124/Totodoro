/*
* File: MediaEnumaration.qml
* Author: michael.godfrey
* Date: 04-20-2025
* Description: MediaEnumaration.qml is a QML file that defines qml enumaration of Media Player.
*/

import QtQuick

QtObject {
    id: root

    enum ButtonForm {
        None,
        Play,
        Pause,
        Next,
        Previous,
        Shuffle,
        Repeat,
        Sound
    }
}
