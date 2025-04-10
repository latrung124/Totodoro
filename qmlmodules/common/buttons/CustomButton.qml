/*
* CustomButton.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the CustomButton component which is used to create a custom button.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Templates as T

T.Button {
    id: control

    property string iconSource: ""
    property color iconColor: "#ffffff"
    property color backgroundColor: "#000000"
    property double iconOpacity: 1.0
    property int backgroundRadius: 0
    property size iconSize: Qt.size(24, 24)

    property alias isShowIcon: background.isShowIcon
    property alias isShowBackground: background.isShowBackground
    property alias backgroundWidth: background.width
    property alias backgroundHeight: background.height

    implicitWidth: Math.max(background.implicitWidth + leftInset + rightInset,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background.implicitHeight + topInset + bottomInset,
                            contentItem.implicitHeight + topPadding + bottomPadding)

    font {
        family: "Helvetica"
        pixelSize: 16
    }

    contentItem: CustomButtonContent {
        id: contentItem

        text: control.text
        font: control.font
    }

    background: CustomButtonBackground {
        id: background

        iconSource: control.iconSource
        iconColor: control.iconColor
        iconOpacity: control.iconOpacity
        backgroundColor: control.backgroundColor
        radius: control.backgroundRadius
        iconWidth: iconSize.width
        iconHeigth: iconSize.height
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true

        onClicked: function() {
            control.clicked();
        }
    }

    states: [
        State {
            name: "hovered"
            when: !mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: control
                iconColor: "#888888"
            }
        },
        State {
            name: "pressed"
            when: mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: control
                iconColor: "#ffffff"
            }
        }
    ]
}
