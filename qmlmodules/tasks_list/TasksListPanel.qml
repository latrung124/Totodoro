/*
* File: TasksListPanel.qml
* Author: dang.nguyen
* Date: 06-04-2025
* Brief: This file contains the TasksListPanel component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property alias backgroundColor: background.color

    implicitWidth: 338
    implicitHeight: 586

	Rectangle {
		id: background
		anchors.fill: parent
	}

	ColumnLayout {
		anchors.fill: parent

		Item {
			Layout.fillWidth: true
			Layout.preferredHeight: 74

			RowLayout {
				width: internal.taskItemWidth
				height: 42
				anchors.centerIn: parent

				Text {
					text: "Tasks List"
					font {
						family: internal.font
						pixelSize: 18
						weight: Font.Bold
					}
				}

				Rectangle {
					Layout.preferredWidth: 24
					Layout.preferredHeight: 24
					Layout.leftMargin: 5

					radius: 10
					color: "#EFEFEF"

					Image {
						anchors.centerIn: parent
						source: "resources/icon/addplus.svg"
					}
				}

				Item {
					Layout.fillWidth: true
				}

				Image {
					source: "resources/icon/menu.svg"
				}
			}
		}

		TasksListView {
			Layout.preferredWidth: internal.taskItemWidth
			Layout.fillHeight: true
			Layout.alignment: Qt.AlignHCenter
		}

		QtObject {
			id: internal

			readonly property int margin: 24
			readonly property int taskItemWidth: root.width - margin * 2

			readonly property string font: "Onest"
		}
	}
}
