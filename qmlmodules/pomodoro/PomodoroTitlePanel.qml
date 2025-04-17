/*
* File: PomodoroTitlePanel.qml
* Author: trung.la
* Date: 04-17-2025
* Description: This file contains the PomodoroTitlePanel component which is used to showing title for the Pomodoro task.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Item {
    id: root

    property alias backgroundColor: background.color

    implicitWidth: 918
    implicitHeight: 82

    Rectangle {
        id: background

        anchors.fill: parent
        color: internal.defaultBackgroundColor
    }

    RowLayout {
        id: titleLayout

        anchors {
            fill: parent
            leftMargin: internal.sideMargin
            rightMargin: internal.sideMargin
        }

        spacing: 50

        RowLayout {
            id: title

            Layout.fillWidth: true
            Layout.preferredHeight: internal.lineHeight
            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

            Item {
                id: titleIconItem

                Layout.preferredWidth: internal.lineHeight
                Layout.preferredHeight: internal.lineHeight
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

                Image {
                    id: titleIcon

                    width: parent.width
                    height: parent.height
                    source: 'resources/panda-icon.png'
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    asynchronous: true
                }
            }

            Item {
                id: titleTextRowItem

                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter

                Row {
                    id: titleTextRow

                    anchors.fill: parent

                    Item {
                        id: titleTextItem

                        width: 200 // TODO: modify to bind with text width
                        height: internal.lineHeight
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            id: titleText

                            width: parent.width
                            height: parent.height

                            anchors {
                                left: parent.left
                                verticalCenter: parent.verticalCenter
                            }
                            verticalAlignment: Text.AlignVCenter

                            font {
                                family: "Onest"
                                pixelSize: 18
                                weight: Font.Bold
                                letterSpacing: 0
                            }

                            lineHeight: 1.0
                            lineHeightMode: Text.FixedHeight
                            text: qsTr("Chinese Learning")
                        }
                    }

                    CustomButton {
                        id: editIconItem

                        width: internal.iconSize
                        height: internal.iconSize
                        anchors.verticalCenter: parent.verticalCenter
                        iconSize: Qt.size(16, 16)

                        isShowIcon: true
                        iconSource: internal.resourcePath + "edit-button.png"
                        isShowBackground: true
                        iconColor: "#000000"
                        backgroundColor: "#efefef"
                        backgroundRadius: 5
                        ToolTip.visible: hovered
                        ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                        ToolTip.text: "Edit"
                    }
                }
            }
        }

        CustomButton {
            id: removeButton

            Layout.preferredWidth: internal.iconSize
            Layout.preferredHeight: internal.iconSize
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

            iconSize: Qt.size(internal.iconSize, internal.iconSize)
            isShowIcon: true
            iconSource: internal.resourcePath + "trash-can.png"
            isShowBackground: false
            iconColor: "#000000"
            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: "Edit"
        }
    }

    QtObject {
        id: internal

        readonly property color defaultBackgroundColor: "#ffffff"
        readonly property int iconSize: 24
        readonly property int sideMargin: 24
        readonly property int lineHeight: 36
        readonly property string resourcePath: "qrc:/qt/qml/PomodoroModule/resources/"
    }
}
