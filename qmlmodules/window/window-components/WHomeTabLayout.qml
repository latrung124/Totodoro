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

    property QtObject model: null

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

                    model: root.model ? root.model.userProfile : null

                    Layout.preferredWidth: 42
                    Layout.fillHeight: true
                }

				TaskGroupListPanel {
					id: taskGroupList

                    model: root.model ? root.model.taskGroups : null

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
                            model: root.model ? root.model.pomodoroTitle : null
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

					Item {
						id: pomodoroPanelItem

						Layout.fillWidth: true
						Layout.fillHeight: true
						Layout.alignment: Qt.AlignLeft

						PomodoroPanel {
							id: pomodoroPanel

							anchors {
								fill: parent
								bottom: parent.bottom
								bottomMargin: 1
							}
							model: root.model ? root.model.pomodoro : null
						}
					}

					Item {
						id: tasksListPanelItem

						Layout.preferredWidth: 338
						Layout.fillHeight: true
						Layout.alignment: Qt.AlignRight

						RoundedRectangle {
							anchors {
								fill: parent
								bottom: parent.bottom
								bottomMargin: 1
							}

							radius: root.radius
							fillColor: internal.rightPanelColor
							roundTopLeft: false
							roundTopRight: false
							roundBottomLeft: false

							TasksListPanel {
								id: tasksListPanel

								anchors.fill: parent
								model: root.model ? root.model.tasks : null
								backgroundColor: "transparent"
							}
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
