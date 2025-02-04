/*
* File: MediaPlayer.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick

Item {
    id: root

    property QtObject mediaPlayerModel: null

    implicitWidth: 1366
    implicitHeight: 115

    Rectangle {
        id: backgroundRect

        anchors {
            fill: parent
            margins: 1
        }
        color: "#000000"
        radius: 8
    }
}
