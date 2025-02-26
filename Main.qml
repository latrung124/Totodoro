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

Window {
    id: root

    objectName: "appWindow"
    visible: true
    width: internal.windowWidth
    height: internal.windowHeight
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

        isFullScreen: root.visibility === Window.FullScreen

        onMaximizeWindow: function() {
            if (root.visibility === Window.FullScreen) {
                root.visibility = Window.Windowed;
            } else {
                root.visibility = Window.FullScreen;
            }
        }

        onMinimizeWindow: function() {
            minimizeAnimation.start();
        }

        onCloseWindow: function() {
            navigator.closeWindow();
            close();
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

    SequentialAnimation {
        id: minimizeAnimation
        ParallelAnimation {
            NumberAnimation { target: root; property: "x"; to: internal.hidePosX; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "y"; to: internal.hidePosY; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "width"; to: internal.hideWidthTarget; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "height"; to: internal.hideHeightTarget; duration: 200; easing.type: Easing.InOutQuad }
        }

        onFinished: function() {
            root.visibility = Window.Minimized;
            root.width = internal.windowWidth;
            root.height = internal.windowHeight;
            root.x = (screen.width - width) / 2;
            root.y = (screen.height - height) / 2;
        }
    }

    QtObject {
        id: internal

        property int hidePosX: Math.floor(Screen.width / 2) - 50
        property int hidePosY: screen.height - 100
        property int hideWidthTarget: 100
        property int hideHeightTarget: 100
        property int minimizeDuration: 200
        property int windowWidth: 1366
        property int windowHeight: 780
    }
}
