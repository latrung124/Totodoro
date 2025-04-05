/*
* File: Window.qml
* Author: michael.godfrey
* Date: 04-03-2025
* Description: This file contains the Window QML component, which is used to create a window with a title bar and a close button.
*/

import QtQuick
import QtQuick.Controls

import CommonModule 1.0

Window {
    id: root

    width: internal.windowWidth
    height: internal.windowHeight
    visible: true
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: internal.setWindowCenterPos()

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#222222"
        opacity: 1
        radius: internal.radius
    }

    WindowDragger {
        id: dragArea

        anchors.fill: parent
        dragTarget: root
        enableDrag: true
    }

    Item {
        id: appNameItem

        anchors {
            top: parent.top
            left: parent.left
            topMargin: 24
            leftMargin: 40
        }

        width: 48
        height: 48

        Image {
            id: appNameImage

            anchors.fill: parent
            source: `resources/app-name.png`
            fillMode: Image.PreserveAspectFit
            smooth: true
        }
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

        onMinimizeWindow: function() {
            minimizeAnimation.start();
        }

        onCloseWindow: function() {
            navigator.closeWindow();
            close();
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
            internal.setWindowCenterPos();
        }
    }

    QtObject {
        id: internal

        property int windowWidth: 1360
        property int windowHeight: 780
        property int radius: 20
        property int hidePosX: Math.floor(Screen.width / 2) - 50
        property int hidePosY: screen.height - 100
        property int hideWidthTarget: 100
        property int hideHeightTarget: 100
        property int minimizeDuration: 200

        function setWindowCenterPos() {
            root.x = (screen.width - width) / 2;
            root.y = (screen.height - height) / 2;
        }
    }
}
