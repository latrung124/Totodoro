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
import PomodoroModule 1.0
import TasksListModule 1.0
import TaskGroupListModule 1.0
import UserProfileModule 1.0

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

        spacing: 0

        Item {
            id: leftPanelItem

            Layout.preferredWidth: internal.leftPanelItemWidth
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft

            RowLayout {
                id: leftPanelLayout

                anchors {
                    fill: parent
					margins: 24
                }

                spacing: 24

                UserProfilePanel {
                    id: userProfile

                    Layout.preferredWidth: 42
                    Layout.fillHeight: true
                }

				TaskGroupListPanel {
					id: taskGroupList

					Layout.fillWidth: true
					Layout.fillHeight: true
					backgroundColor: internal.backgroundColor
				}
            }
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
                    Layout.preferredHeight: internal.rightPanelTitleHeight
                    Layout.alignment: Qt.AlignTop

                    RoundedRectangle {
                        anchors.fill: parent
                        radius: root.radius
                        fillColor: internal.rightPanelColor
                        roundTopLeft: false
                        roundBottomLeft: false
                        roundBottomRight: false

                        PomodoroTitlePanel {
                            id: title

                            anchors.fill: parent
                            backgroundColor: "transparent"
                        }
                    }
                }

                RowLayout {
                    id: rightPanelContent

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignBottom

                    spacing: 1

                    PomodoroPanel {
                        id: pomodoroPanel

                        Layout.preferredWidth: internal.pomodoroPanelWidth
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignLeft
                    }

                    RoundedRectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignRight
                        radius: root.radius
                        fillColor: internal.rightPanelColor
                        roundTopLeft: false
                        roundTopRight: false
                        roundBottomLeft: false

                        TasksListPanel {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            backgroundColor: "transparent"
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
        readonly property int leftPanelItemWidth: 410
        readonly property int rightPanelTitleHeight: 82
        readonly property int pomodoroPanelWidth: 580
    }
}
