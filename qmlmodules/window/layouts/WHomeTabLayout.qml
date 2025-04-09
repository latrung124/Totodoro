/*
* File: WHomeTabLayout.qml
* Author: trung.la
* Date: 04-09-2025
* Description: This file contains the Home Tab Layout QML component for window,
* which is used to create a home tab layout for the application.
*/

import QtQuick
import QtQuick.Layouts

import CommonModule 1.0

Item {
    id: root

    property alias radius: backgroundRect.radius
    property alias backgroundColor: backgroundRect.color

    implicitWidth: 1328
    implicitHeight: 668

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: internal.backgroundColor
    }

    RowLayout {
        id: layout

        anchors.fill: parent

        Item {
            id: leftPanelItem

            Layout.preferredWidth: 410
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft
        }

        Item {
            id: rightPanelItem

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignRight

            ColumnLayout {
                id: rightPanelLayout

                anchors.fill: parent

                spacing: 1

                Item {
                    id: rightPanelTitle

                    Layout.fillWidth: true
                    Layout.preferredHeight: 82
                    Layout.alignment: Qt.AlignTop

                    RoundedRectangle {
                        anchors.fill: parent
                        radius: root.radius
                        fillColor: internal.rightPanelColor
                        roundTopLeft: false
                        roundBottomLeft: false
                        roundBottomRight: false
                    }
                }

                RowLayout {
                    id: rightPanelContent

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignBottom

                    spacing: 1

                    Item {
                        id: pomodoroItem

                        Layout.preferredWidth: 580
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignLeft

                        Rectangle {
                            anchors.fill: parent
                            color: internal.rightPanelColor
                        }
                    }

                    Item {
                        id: taskListItem

                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignRight

                        RoundedRectangle {
                            anchors.fill: parent
                            radius: root.radius
                            fillColor: internal.rightPanelColor
                            roundTopLeft: false
                            roundTopRight: false
                            roundBottomLeft: false
                        }
                    }
                }
            }
        }
    }

    QtObject {
        id: internal

        readonly property color backgroundColor: "#efefef"
        readonly property color rightPanelColor: "#ffffff"
    }
}
