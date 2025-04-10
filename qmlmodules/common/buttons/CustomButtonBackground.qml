/*
* CustomButtonBackground.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the CustomButtonBackground component which is used to create a custom button background.
*/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Item {
    id: root

    property bool isShowBackground: true
    property bool isShowIcon: false

    property alias iconSource: icon.source
    property alias iconColor: iconOverlay.color
    property alias backgroundColor: background.color
    property alias iconOpacity: iconOverlay.opacity
    property alias radius: background.radius
    property alias iconWidth: icon.sourceSize.width
    property alias iconHeigth: icon.sourceSize.height

    implicitWidth: internal.backgroundWidth
    implicitHeight: internal.backgroundHeight

    Rectangle {
        id: background

        visible: isShowBackground
        anchors.fill: parent
        color: internal.backgroundColor
        radius: internal.backgroundRadius
    }

    Image {
        id: icon

        visible: false
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    ColorOverlay {
        id: iconOverlay

        visible: isShowIcon
        anchors.fill: icon
        source: icon
        color: internal.iconColor
    }

    QtObject {
        id: internal

        readonly property int backgroundWidth: 100
        readonly property int backgroundHeight: 50
        readonly property int backgroundRadius: 4
        readonly property color backgroundColor: "#000000"
        readonly property color iconColor: "#333333"
    }
}
