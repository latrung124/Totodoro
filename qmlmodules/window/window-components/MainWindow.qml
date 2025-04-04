/*
* File: Window.qml
* Author: michael.godfrey
* Date: 04-03-2025
* Description: This file contains the Window QML component, which is used to create a window with a title bar and a close button.
*/

import QtQuick

Window {
    id: root

    width: internal.windowWidth
    height: internal.windowHeight
    visible: true
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: function() {
        x = (screen.width - width) / 2;
        y = (screen.height - height) / 2;
    }

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#222222"
        opacity: 1
        radius: internal.radius
    }

    WindowControl {
        id: windowControl

        anchors {
            top: parent.top
            right: parent.right
            topMargin: 37
            rightMargin: 40
        }

        width: 104
        height: 24

        spacing: 16
    }

    QtObject {
        id: internal

        property int windowWidth: 1360
        property int windowHeight: 780
        property int radius: 20
    }
}
