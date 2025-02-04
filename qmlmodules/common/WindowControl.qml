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
        Item {
            id: minimizeItem
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                id: minimizeImage
                anchors.fill: parent
                source: `resources/window/minimize-button.png`
                fillMode: Image.PreserveAspectFit
            }
        }
        Item {
            id: maximizeItem
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                id: maximizeImage
                anchors.fill: parent
                source: `resources/window/maximize-button.png`
                fillMode: Image.PreserveAspectFit
            }
        }
        Item {
            id: closeItem
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                id: closeImage
                anchors.fill: parent
                source: `resources/window/close-button.png`
                fillMode: Image.PreserveAspectFit
            }
            MouseArea {
                id: closeArea
                anchors.fill: parent
                onClicked: {
                    closeWindowClicked()
                }
            }
        }
    }
}
