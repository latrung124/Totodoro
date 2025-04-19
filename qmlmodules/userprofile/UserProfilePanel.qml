/*
* File: UserProfilePanel.qml
* Author: trung.la
* Date: 04-19-2025
* Description: This file contains the UserProfilePanel component which is used to show the user profile information.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Item {
    id: root

    implicitWidth: 42
    implicitHeight: 620

    ColumnLayout {
        id: layout

        anchors.fill: parent
        spacing: 16

        Item {
            id: profileItem

            Layout.preferredWidth: 42
            Layout.preferredHeight: 42
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

            Image {
                id: profilePicture

                width: parent.width
                height: parent.height
                source: `resources/default-avatar.png`
                fillMode: Image.PreserveAspectFit
                smooth: true
                asynchronous: true
            }
        }

        Rectangle {
            id: lineRect

            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter
            color: "#222222"
            opacity: 0.1
        }

        ColumnLayout {
            id: settingsLayout

            Layout.preferredWidth: 24
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            spacing: 16

            Item {
                Layout.preferredWidth: 24
                Layout.preferredHeight: 24
                Layout.alignment: Qt.AlignHCenter

                CustomButton {
                    width: parent.width
                    height: parent.height
                    iconSource: internal.resourcePath + "settings-button.png"
                    iconColor: internal.defaultColorIcon
                    isShowIcon: true
                    isShowBackground: false
                    ToolTip.visible: hovered
                    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                    ToolTip.text: "Settings"
                }
            }

            Item {
                Layout.preferredWidth: 24
                Layout.preferredHeight: 24
                Layout.alignment: Qt.AlignHCenter

                CustomButton {
                    width: parent.width
                    height: parent.height
                    iconSource: internal.resourcePath + "question-button.png"
                    iconColor: internal.defaultColorIcon
                    isShowIcon: true
                    isShowBackground: false
                    ToolTip.visible: hovered
                    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                    ToolTip.text: "Question"
                }
            }

            Item {
                Layout.preferredWidth: 24
                Layout.preferredHeight: 24
                Layout.alignment: Qt.AlignHCenter

                CustomButton {
                    width: parent.width
                    height: parent.height
                    iconSource: internal.resourcePath + "language-button.png"
                    iconColor: internal.defaultColorIcon
                    isShowIcon: true
                    isShowBackground: false
                    ToolTip.visible: hovered
                    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                    ToolTip.text: "Language"
                }
            }
        }
    }

    QtObject {
        id: internal

        readonly property color defaultColorIcon: "#000000"
        readonly property string resourcePath: "qrc:/qt/qml/UserProfileModule/resources/"
    }
}
