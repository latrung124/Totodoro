/*
* File: MenuTab.qml
* Author: trung.la
* Date: 04-06-2025
* Description: This file contains the MenuTab QML component, which is used to create a tab for the menu bar.
*/

import QtQuick
import QtQuick.Controls.impl
import QtQuick.Templates as T

import CommonModule 1.0

T.TabButton {
    id: menuTab

    property string iconSource: ""
    property color iconColor: "#ffffff"
    property color backgroundColor: "#000000"

    property alias isShowIcon: background.isShowIcon
    property alias isShowBackground: background.isShowBackground
    property alias backgroundWidth: background.width
    property alias backgroundHeight: background.height

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                             contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                              contentItem.implicitHeight + topPadding + bottomPadding)

    font {
        family: "Helvetica"
        pixelSize: 16
    }

    contentItem: CustomButtonContent {
        id: contentItem

        text: menuTab.text
        font: menuTab.font
    }

    background: CustomButtonBackground {
        id: background

        iconSource: menuTab.iconSource
        iconColor: menuTab.iconColor
        backgroundColor: menuTab.backgroundColor
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true

        onClicked: function() {
            menuTab.clicked();
        }
    }


    states: [
        State {
            name: "hovered"
            when: !mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: menuTab
                iconColor: "#888888"
            }
        },
        State {
            name: "pressed"
            when: mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: menuTab
                iconColor: "#ffffff"
            }
        }
    ]
}
