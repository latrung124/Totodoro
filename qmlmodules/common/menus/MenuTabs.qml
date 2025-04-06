/*
* File: MenuTabs.qml
* Author: trung.la
* Date: 04-06-2025
* Description: This file contains the MenuTabs QML component, which is used to create a menu bar with tabs for the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Templates as T

T.TabBar {
    id: control

    property int tabWidth: 24
    property int tabHeight: 24

    property alias backgroundColor: background.color
    property alias tabModels: repeater.model
    property alias tabDelegate: repeater.delegate
    property alias tabSpacing: row.spacing

    topPadding: 0
    bottomPadding: 0
    leftPadding: 0
    rightPadding: 0

    topInset: 0
    bottomInset: 0
    leftInset: 0
    rightInset: 0

    implicitWidth: contentItem.implicitWidth
    implicitHeight: tabHeight

    spacing: 0
    padding: 0

    font {
        family: "Helvetica"
        pixelSize: 16
    }

    // Layout fix: Anchor Row to top to prevent vertical offset
    contentItem: Item {
        height: control.tabHeight
        width: row.implicitWidth

        Row {
            id: row
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: control.tabSpacing
            height: control.tabHeight

            Repeater {
                id: repeater

                delegate: MenuTab {
                    id: tab

                    width: control.tabWidth
                    height: control.tabHeight

                    iconSource: model.iconSource
                    iconColor: model.iconColor
                    isShowIcon: model.isShowIcon
                    isShowBackground: model.isShowBackground
                    text: model.text

                    ToolTip.visible: hovered
                    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                    ToolTip.text: model.toolTipText
                }
            }
        }
    }

    background: Rectangle {
        id: background
        color: control.palette.window
    }
}
