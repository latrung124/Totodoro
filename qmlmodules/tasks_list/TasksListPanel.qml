/*
* File: TasksListPanel.qml
* Author: dang.nguyen
* Date: 06-04-2025
* Brief: This file contains the TasksListPanel component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Item {
	id: root

	property QtObject model: null

	property alias backgroundColor: background.color

    implicitWidth: 338
    implicitHeight: 586

	onModelChanged: {
		console.log("TasksListPanel: model changed");
		if (model) {
            tasksListView.model = root.model;
		} else {
			console.log("TasksListPanel: model is null");
		}
	}

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

					CustomButton {
						width: parent.width
						height: parent.height
						iconSource: internal.commonModuleResourcePath + "addplus.svg"
						iconColor: internal.black
						isShowIcon: true
						isShowBackground: false
						ToolTip.visible: hovered
						ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
						ToolTip.text: "Add"
					}
				}

				Item {
					Layout.fillWidth: true
				}

				Item {
					Layout.preferredWidth: 24
					Layout.preferredHeight: 24
					Layout.leftMargin: 5

					CustomButton {
						width: parent.width
						height: parent.height
						iconSource: internal.commonModuleResourcePath + "menu.svg"
						iconColor: internal.black
						isShowIcon: true
						isShowBackground: false
						ToolTip.visible: hovered
						ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
						ToolTip.text: "Menu"
					}
				}
			}
		}

		TasksListView {
			id: tasksListView

			Layout.preferredWidth: internal.taskItemWidth
			Layout.fillHeight: true
			Layout.alignment: Qt.AlignHCenter
		}

		QtObject {
			id: internal

			readonly property int margin: 24
			readonly property int taskItemWidth: root.width - margin * 2

			readonly property color black: "#000000"

			readonly property string font: "Onest"
			readonly property string commonModuleResourcePath: "qrc:/qt/qml/CommonModule/resources/icon/"
		}
	}
}
