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

import CommonModule 1.0
import TasksListModule 1.0

Rectangle {
	id: root

	property bool selected: false

	implicitWidth: 296
	implicitHeight: 173

	radius: 10
	color: internal.backgroundColor

	ColumnLayout {
		anchors {
			fill: parent
			margins: 19
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: moreIcon.height

			Text {
				Layout.alignment: Qt.AlignLeft

				font {
					family: internal.font
					pixelSize: 12
					weight: Font.Medium
				}
				color: "#538EF5"

				text: "Low Priority"
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
				border.width: 1

				Image {
					anchors {
						fill: parent
						centerIn: parent
						margins: 1
					}
					fillMode: Image.PreserveAspectFit
					source: "resources/icon/demon.png"
				}
			}

			Text {
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
				text: "72 Solomon Demon redrawing & " +
					  "Chinese Zodiac 2025 making"
			}
		}

		Text {
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
			text: "Remake the 72 Solomon demon and " +
				  "New Year Chinese Zodiac 2025"
		}

		TaskGroupProgressBar {
			id: progressBar

			Layout.fillWidth: true
			Layout.preferredHeight: 6
			totalTasks: 8
			completedTasks: 6
			isSelected: root.selected
		}

		RowLayout {
			Layout.fillWidth: true
			Layout.preferredHeight: calendarIcon.height

			Text {
				Layout.alignment: Qt.AlignLeft

				font {
					family: internal.font
					pixelSize: 12
				}
				color: internal.describeColor
				text: "6/8 completed"
			}

			Item {
				Layout.fillWidth: true
			}

			RowLayout {
				Layout.preferredWidth: calendarIcon.width + dayLeft.width + internal.spacing
				Layout.preferredHeight: calendarIcon.height

				OverlayedImage {
					id: calendarIcon
					color: internal.selectedColor
					source: internal.resourcePath + "calendar.svg"
				}

				Text {
					id: dayLeft

					Layout.leftMargin: internal.spacing
					Layout.alignment: Qt.AlignLeft

					font {
						family: internal.font
						pixelSize: 12
					}
					color: internal.selectedColor
					text: "1 day left"
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
		readonly property color selectedColor: root.selected ? white : black
		readonly property color describeColor: root.selected ? mediumGray : darkGray
		readonly property color taskProgressBarColor: root.selected ? white : darkGray
	}
}
