/*
* File: TaskGroupItem.qml
* Author: dang.nguyen
* Date: 19-04-2025
* Brief: This file contains the TaskGroupItem component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

import App.Enums 1.0
import CommonModule 1.0
import TasksListModule 1.0

Item {
	id: root

	property bool selected: false
    property int priority: PriorityType.Medium
	property string name: ""
	property string description: ""
	property int completedTasks: 0
	property int totalTasks: 0
	property string icon: ""

	implicitWidth: 296
	implicitHeight: 173

	Rectangle {
		id: background

		anchors.fill: parent
		radius: 10
		color: internal.backgroundColor
	}

	ColumnLayout {
		anchors {
			fill: parent
			margins: 19
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: moreIcon.height

			Text {
				id: taskPriorityText

				Layout.alignment: Qt.AlignLeft

				font {
					family: internal.font
					pixelSize: 12
					weight: Font.Medium
				}
				color: "#538EF5"
				text: internal.getPriorityText(root.priority)
			}

			Item {
				Layout.fillWidth: true
			}

			Item {
				id: moreIcon

				Layout.preferredWidth: 24
				Layout.preferredHeight: 24
				Layout.alignment: Qt.AlignRight

				CustomButton {
					width: parent.width
					height: parent.height
					iconSource: internal.commonModuleResourcePath + "ellipsis.svg"
					iconColor: internal.selectedColor
					isShowIcon: true
					isShowBackground: false
					ToolTip.visible: hovered
					ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
					ToolTip.text: "More"
				}
			}
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: 36
			Layout.alignment: Qt.AlignBottom

			Rectangle {
				Layout.preferredWidth: parent.height
				Layout.preferredHeight: parent.height
				Layout.alignment: Qt.AlignLeft

				radius: 4
				color: internal.backgroundIconColor

				OverlayedImage {
					anchors {
						centerIn: parent
					}
					color: internal.selectedColor
					source: internal.resourcePath + root.icon
				}
			}

			Text {
				id: groupNameText

				Layout.fillWidth: true
				Layout.preferredHeight: parent.height
				Layout.leftMargin: 10
				Layout.alignment: Qt.AlignLeft

				font {
					family: internal.font
					pixelSize: 14
					weight: Font.DemiBold
				}
				color: internal.selectedColor
				elide: Text.ElideRight
				maximumLineCount: 2
				wrapMode: Text.Wrap
				text: root.name
			}
		}

		Text {
			id: groupDescriptionText

			Layout.fillWidth: true
			Layout.fillHeight: true

			font {
				family: internal.font
				pixelSize: 12
				weight: Font.DemiBold
			}
			color: internal.describeColor

			elide: Text.ElideRight
			maximumLineCount: 2
			wrapMode: Text.Wrap
			text: root.description
		}

		TaskGroupProgressBar {
			id: progressBar

			Layout.fillWidth: true
			Layout.preferredHeight: 6
			totalTasks: root.totalTasks
			completedTasks: root.completedTasks
			isSelected: root.selected
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: calendarIcon.height

			Text {
				id: taskProgressText

				Layout.alignment: Qt.AlignLeft

				font {
					family: internal.font
					pixelSize: 12
				}
				color: internal.describeColor
				text: internal.getTaskProgressText(root.completedTasks, root.totalTasks)
			}

			Item {
				Layout.fillWidth: true
			}

			RowLayout {
                Layout.preferredWidth: calendarIcon.width + dayLeftText.width + internal.spacing
				Layout.preferredHeight: calendarIcon.height

				OverlayedImage {
					id: calendarIcon
					color: internal.selectedColor
					source: internal.resourcePath + "calendar.svg"
				}

				Text {
					id: dayLeftText

					Layout.leftMargin: internal.spacing
					Layout.alignment: Qt.AlignLeft

					font {
						family: internal.font
						pixelSize: 12
					}
					color: internal.selectedColor
					text: internal.getDayLeftText()
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property string resourcePath: "qrc:/qt/qml/TaskGroupListModule/resources/icon/"
		readonly property string commonModuleResourcePath: "qrc:/qt/qml/CommonModule/resources/icon/"

		readonly property string font: "Onest"
		readonly property int spacing: 4

		readonly property color mediumGray: "#CDCDCD"
		readonly property color darkGray : "#7F7F7F"
		readonly property color darkestGray: "#222222"
		readonly property color white: "#FFFFFF"
		readonly property color black: "#000000"

		readonly property color backgroundColor: root.selected ? darkestGray : white
		readonly property color backgroundIconColor: root.selected ? "#494949" : "#EFEFEF"
		readonly property color selectedColor: root.selected ? white : black
		readonly property color describeColor: root.selected ? mediumGray : darkGray
		readonly property color taskProgressBarColor: root.selected ? white : darkGray

		function getPriorityText(priority) {
			switch (priority) {
				case PriorityType.High:
					return "High Priority";
				case PriorityType.Medium:
					return "Medium Priority";
				case PriorityType.Low:
					return "Low Priority";
				default:
					return "";
			}
		}

		function getTaskProgressText(completedTasks, totalTasks) {
			return completedTasks + "/" + totalTasks + " completed";
		}

		function getDayLeftText() {
			// TODO: Implement this function to calculate the number of days left
			return "3 days left";
		}
	}
}
