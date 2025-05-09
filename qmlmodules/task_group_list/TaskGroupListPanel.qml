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

	property QtObject model: null

	property alias backgroundColor: background.color

	implicitWidth: 296
	implicitHeight: 586

	onModelChanged: {
		console.log("TaskGroupListPanel model changed!");
		if (model) {
			taskGroupListView.model = root.model;
		} else {
			console.log("TaskGroupListPanel model is null!");
		}
	}

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

			delegate: TaskGroupItem {
				width: taskGroupListView.width
				height: 173
				name: model.name
				description: model.description
				completedTasks: model.completedTasks
				totalTasks: model.totalTasks
				priority: model.priority

				selected: ListView.isCurrentItem
				MouseArea {
					anchors.fill: parent
					onClicked: taskGroupListView.currentIndex = index
				}
			}
		}
	}
}
