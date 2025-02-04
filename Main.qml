/*
* File: Main.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0
import MediaPlayerModule 1.0

ApplicationWindow {
    id: root

    objectName: "appWindow"
    visible: true
    width: 1366
    height: 780
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: function() {
        x = (screen.width - width) / 2;
        y = (screen.height - height) / 2;
    }

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#000000"
        opacity: 1
        radius: 8
        border {
            color: "#ffffff"
            width: 0.5
        }
    }

    WindowControl {
        id: windowControl

        anchors {
            top: parent.top
            topMargin: 10
            right: parent.right
            rightMargin: 5
        }
    }

    MediaPlayer {
        id: mediaPlayer

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
    }
}
