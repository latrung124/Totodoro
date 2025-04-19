/*
* File: TaskGroupListPanel.qml
* Author: dang.nguyen
* Date: 19-04-2025
* Brief: This file contains the TaskGroupListPanel component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property alias backgroundColor: background.color

	implicitWidth: 296
	implicitHeight: 586

	Rectangle {
		id: background
		anchors.fill: parent
	}

	ColumnLayout {
		anchors.fill: parent

		TaskGroupListTitlePanel {
			id: title

			Layout.fillWidth: true
			Layout.preferredHeight: 42
		}

		ListView {
			id: taskGroupListView

			Layout.fillWidth: true
			Layout.fillHeight: true

			clip: true
			spacing: 20

			model: 5
			delegate: TaskGroupItem {
				required property int index

				width: taskGroupListView.width
				height: 173

				selected: ListView.isCurrentItem
				MouseArea {
					anchors.fill: parent
					onClicked: taskGroupListView.currentIndex = index
				}
			}
		}
	}
}
