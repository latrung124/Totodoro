/*
* File: WindowControl.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: windowControl

    signal closeWindowClicked()
    signal minimizeWindowClicked()
    signal maximizeWindowClicked()

    implicitWidth: 80 // Consider change the size of the window control buttons with different sizes
    implicitHeight: 20

    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 10
        CustomButton {
            id: minimizeItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `resources/window/minimize-button.png`
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
        }

        CustomButton {
            id: maximizeItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `resources/window/maximize-button.png`
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
        }

        CustomButton {
            id: closeItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: `resources/window/close-button.png`
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
        }
    }

    QtObject {
        id: internal

        readonly property color enableColor: "#FFFFFF"
        readonly property color disableColor: "#666666"
    }
}
