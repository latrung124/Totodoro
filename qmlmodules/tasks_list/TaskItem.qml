/*
* File: TaskItem.qml
* Author: dang.nguyen
* Date: 06-04-2025
* Brief: This file contains the TaskItem component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

import App.Enums 1.0

Item {
	id: root

	property bool selected: false
	property string name: ""
	property string description: ""
    property int priority: PriorityType.Medium
	property int completedPomodoros: 0
	property int totalPomodoros: 0
	property string dueDate: "" // TODO: handle due date formatting

	Rectangle {
		id: checkBox

		width: image.implicitWidth
		height: image.implicitHeight
		radius: width/2

		border.width: 2
		color: root.selected ? internal.darkestGray : internal.white

		OverlayedImage {
			id: image
			visible: root.selected

			source: "resources/icon/completed.svg"
			color: internal.white
		}
	}

	ColumnLayout {
		width: internal.taskItemContentWidth
		height: parent.height
		anchors.right: parent.right

		Text {
			Layout.alignment: Qt.AlignLeft

			font {
				family: internal.font
				pixelSize: 12
				weight: Font.Medium
			}
			text: "Today, 21:00:00"
		}

		Rectangle {
			Layout.fillWidth: true
			Layout.preferredHeight: 101

			radius: 10
			color: internal.backgroundColor

			ColumnLayout {
				implicitWidth: parent.width
				implicitHeight: 80
				anchors {
					verticalCenter: parent.verticalCenter
					left: parent.left
					leftMargin: 20
				}

				RowLayout {
					Layout.fillWidth: true
					Layout.preferredHeight: priority.implicitHeight

					Image {
						id: priority
						source: internal.getTaskPriorityIcon(root.priority)
					}

					Text {
						Layout.alignment: Qt.AlignLeft

						font {
							family: internal.font
							pixelSize: 12
							weight: Font.DemiBold
						}
						color: internal.textColor
						text: internal.getTaskPriorityText(root.priority)
					}

					Rectangle {
						Layout.preferredWidth: 1
						Layout.preferredHeight: 16

						color: internal.verticalBarColor
					}

					Text {
						Layout.alignment: Qt.AlignLeft

						font {
							family: internal.font
							pixelSize: 12
							weight: Font.DemiBold
						}
						color: internal.textColor
						text: "2 Pomodoros"
					}

					Item {
						Layout.fillWidth: true
					}
				}

				RowLayout {
					Layout.fillWidth: true
					Layout.preferredHeight: flag.implicitHeight

					OverlayedImage {
						id: flag
						source: "resources/icon/flag.svg"
						color: root.selected ? internal.white : internal.darkestGray
					}

					Text {
						id: taskName

						Layout.alignment: Qt.AlignLeft

						font {
							family: internal.font
							pixelSize: 14
							weight: Font.DemiBold
						}
						color: internal.textColor
						text: root.name
					}

				}

				Text {
					id: taskDescription

					font {
						family: internal.font
						pixelSize: 12
						weight: Font.Normal
					}
					color: internal.descriptionColor
					elide: Text.ElideLeft
					text: root.description
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int spacing: 12
		readonly property int taskItemContentWidth: root.width - checkBox.width - spacing

		readonly property string font: "Onest"

		readonly property color lightestGray : "#F9F9F9"
		readonly property color mediumGray: "#CDCDCD"
		readonly property color lightGray: "#E6E6E6"
		readonly property color darkGray : "#7F7F7F"
		readonly property color darkestGray: "#222222"
		readonly property color white: "#FFFFFF"
		readonly property color whiteAlpha10: Qt.rgba(1, 1, 1, 0.1)

		readonly property color textColor: root.selected ? white : darkestGray
		readonly property color backgroundColor: root.selected ? darkestGray : lightestGray
		readonly property color verticalBarColor: root.selected ? whiteAlpha10 : lightGray
		readonly property color descriptionColor: root.selected ? mediumGray : darkGray

		function getTaskPriorityText(priority) {
			switch (priority) {
				case PriorityType.Low:
					return "Low";
				case PriorityType.Medium:
					return "Medium";
				case PriorityType.High:
					return "High";
				default:
					return "";
			}
		}

		function getTaskPriorityIcon(priority) {
			switch (priority) {
				case PriorityType.Low:
					return "resources/priority/low.svg";
				case PriorityType.Medium:
					return "resources/priority/medium.svg";
				case PriorityType.High:
					return "resources/priority/high.svg";
				default:
					return "";
			}
		}
	}
}
