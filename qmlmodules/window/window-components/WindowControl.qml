/*
* File: WindowControl.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Item {
    id: windowControl

    signal closeWindow()
    signal minimizeWindow()
    signal maximizeWindow()

    property bool isContainedMinimizeBtn: false
    property bool isContainMaximizeBtn: false
    property bool isFullScreen: false
    property int spacing: 10

    property alias minimizedBtnImage: minimizeItem.iconSource
    property alias minimizedBtnColor: minimizeItem.iconColor
    property alias maximizedBtnImage: maximizeItem.iconSource
    property alias maximizedBtnColor: maximizeItem.iconColor

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
            iconSource: internal.resourcePath + "minimize-button.png"
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: "Minimize"

            onClicked: function() {
                minimizeWindow();
            }
        }

        CustomButton {
            id: maximizeItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: internal.resourcePath + (isFullScreen ? "restore-button.png" : "maximize-button.png")
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: isFullScreen ? "Restore" : "Maximize"

            onClicked: function() {
                maximizeWindow();
            }
        }

        CustomButton {
            id: closeItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            iconSource: internal.resourcePath + "close-button.png"
            iconColor: internal.enableColor
            isShowIcon: true
            isShowBackground: false
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: "Close"

            onClicked: function() {
                closeWindow();
            }
        }
    }

    QtObject {
        id: internal

        readonly property color enableColor: "#FFFFFF"
        readonly property color disableColor: "#666666"
        readonly property string resourcePath: "qrc:/qt/qml/WindowModule/resources/"
    }
}
