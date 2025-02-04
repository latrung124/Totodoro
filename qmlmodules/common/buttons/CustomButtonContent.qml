/*
* CustomButtonContent.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the CustomButtonContent component which is used to create a custom button content.
*/

import QtQuick
import QtQuick.Controls

Item {
    id: root

    property alias text: contentText.text
    property alias font: contentText.font
    property alias color: contentText.color

    implicitHeight: internal.contentHeight
    implicitWidth: internal.contentWidth

    Text {
        id: contentText

        anchors.fill: root
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font {
            family: "Helvetica"
            pixelSize: 16
        }
        elide: Text.ElideMiddle
        textFormat: Text.PlainText
        text: "Button"

        MouseArea {
            id: mouseArea

            anchors.fill: contentText
            hoverEnabled: true
            propagateComposedEvents: true
            acceptedButtons: Qt.NoButton
        }
    }

    QtObject {
        id: internal

        readonly property int contentWidth: 100
        readonly property int contentHeight: 50
    }
}