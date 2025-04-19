/*
* File: TaskGroupProgressBar.qml
* Author: trung.la
* Date: 20-04-2025
* Brief: This file contains the TaskGroupProgressBar component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
	id: root

	property int totalTasks: 1
	property int completedTasks: 0
	property int spacing: 2
	property bool isSelected: false

	implicitWidth: 264
	implicitHeight: 6

	RowLayout {
		id: layout

		anchors.fill: parent
		spacing: root.spacing

		Repeater {
			id: taskRepeater

			model: totalTasks

			Rectangle {
				id: taskItem

				required property int index
				width: root.totalTasks > 1 ? ((parent.width - (root.totalTasks - 1) * root.spacing) / root.totalTasks) : parent.width
				height: parent.height
				color: internal.calculateTaskColor(taskItem.index)
			}
		}
	}

	QtObject {
		id: internal

		readonly property color completedDefaultColor: "#000000"
		readonly property color incompletedDefaultColor: "#d9d9d9"
		readonly property color selectedCompletedDefaultColor: "#ffffff"
		readonly property color selectedInCompletedDefaultColor: "#575757"

		function calculateTaskColor(index) {
			if (index < root.completedTasks) {
				return root.isSelected ? internal.selectedCompletedDefaultColor : internal.completedDefaultColor;
			} else {
				return root.isSelected ? internal.selectedInCompletedDefaultColor : internal.incompletedDefaultColor;
			}
		}
	}
}
