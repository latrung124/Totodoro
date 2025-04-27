/*
* File: TaskGroupListTitlePanel.qml
* Author: dang.nguyen
* Date: 19-04-2025
* Brief: This file contains the TaskGroupListTitlePanel component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Item {
	id: root

	implicitWidth: 296
	implicitHeight: 42

	RowLayout {
		anchors.fill: parent
		spacing: 5

		Text {
			font {
				family: internal.font
				pixelSize: 18
				weight: Font.Bold
			}
			text: "Task Group List"
		}

        CustomButton {
            id: searchButton

            Layout.preferredWidth: 24
            Layout.preferredHeight: 24
            iconSize: Qt.size(16, 16)
            backgroundRadius: 5
            iconSource: internal.commonModuleResourcePath + "search.svg"
            isShowIcon: true
            iconColor: internal.black
            backgroundColor: internal.white
            isShowBackground: true
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: "Search"
        }

        CustomButton {
            id: addButton

            Layout.preferredWidth: 24
            Layout.preferredHeight: 24
            iconSize: Qt.size(16, 16)
            backgroundRadius: 5
            iconSource: internal.commonModuleResourcePath + "addplus.svg"
            isShowIcon: true
            iconColor: internal.black
            backgroundColor: internal.white
            isShowBackground: true
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: "Add"
        }

		Item {
			Layout.fillWidth: true
		}

		Item {
			Layout.preferredWidth: 24
			Layout.preferredHeight: 24

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

	QtObject {
		id: internal

        readonly property color white: "#ffffff" // TODO: refactor to basic color
        readonly property color black: "#000000" // TODO: refactor to accent color
		readonly property string font: "Onest"

		readonly property string commonModuleResourcePath: "qrc:/qt/qml/CommonModule/resources/icon/"
	}
}
