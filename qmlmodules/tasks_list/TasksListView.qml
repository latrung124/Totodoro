/*
* File: TasksListView.qml.qml
* Author: dang.nguyen
* Date: 06-04-2025
* Brief: This file contains the TasksListView.qml component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property QtObject model: null

	Item {
		implicitWidth: 16
		implicitHeight: parent.height

		ListView {
			implicitWidth: 2
			implicitHeight: parent.height
			anchors.centerIn: parent

			clip: true
			spacing: internal.spacing

			model: parent.height / (internal.height + internal.spacing)

			delegate: Rectangle {
				implicitWidth: 2
				implicitHeight: internal.height
				color: internal.mediumGray
			}
		}
	}

	ListView {
		id: tasksListView

		anchors.fill: parent

		clip: true
		spacing: 20
		model: 6

		delegate: TaskItem {
			implicitWidth: root.width
			implicitHeight: 124

			selected: ListView.isCurrentItem
			MouseArea {
				anchors.fill: parent
				onClicked: {
					tasksListView.currentIndex = index;
				}
			}
		}
	}

	QtObject {
		id: internal

		readonly property int height: 10
		readonly property int spacing: 6
		readonly property color mediumGray: "#CDCDCD"
	}
}
