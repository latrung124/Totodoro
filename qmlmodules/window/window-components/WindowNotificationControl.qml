/*
* File: WindowNotificationControl.qml
* Author: trung.la
* Date: 04-19-2025
* Description: WindowNotificationControl is a QML component that provides a notification control for the window.
*/

import QtQuick

Item {
    id: root

    property int notificationNumber: 0
    property color iconColor: "#ffffff"
    property color numberBackgroundColor: "#ff0000"
    property color numberColor: "#ffffff"

    signal clicked()

    implicitWidth: 38
    implicitHeight: 38

    Rectangle {
        id: notificationIcon

        anchors {
            fill: parent
            margins: 2
        }

        color: root.iconColor
        radius: 10

        Image {
            id: iconImage

            width: 24
            height: 24
            anchors.centerIn: parent
            source: internal.resourcePath + "notification-button.png"
            fillMode: Image.PreserveAspectFit
            smooth: true
            asynchronous: true
        }
    }

    Rectangle {
        id: notificationNumber

        width: 16
        height: 16

        anchors {
            right: parent.right
            top: parent.top
        }

        color: root.numberBackgroundColor
        radius: 8

        Text {
            id: numberText

            anchors.centerIn: parent

            font {
                family: "Quicksand"
                weight: Font.Bold
                pixelSize: root.notificationNumber > 9 ? 10 : 12
                letterSpacing: 0
            }

            color: root.numberColor
            lineHeight: 1.0
            lineHeightMode: Text.FixedHeight
            text: root.notificationNumber > 9 ? "9+" : root.notificationNumber.toString()
        }
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: function() {
            root.clicked();
        }
    }

    states: [
        State {
            name: "hovered"
            when: !mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: notificationIcon
                opacity: 0.8
            }

            PropertyChanges {
                target: notificationNumber
                opacity: 0.8
            }
        },
        State {
            name: "pressed"
            when: mouseArea.pressed && mouseArea.containsMouse
            PropertyChanges {
                target: notificationIcon
                opacity: 0.5
            }

            PropertyChanges {
                target: notificationNumber
                opacity: 0.5
            }
        }
    ]

    transitions: [
        Transition {
            PropertyAnimation {
                target: notificationIcon
                property: "opacity"
                duration: 100
                easing.type: Easing.InOutQuad
            }

            PropertyAnimation {
                target: notificationNumber
                property: "opacity"
                duration: 100
                easing.type: Easing.InOutQuad
            }
        }
    ]

    QtObject {
        id: internal

        readonly property string resourcePath: "qrc:/qt/qml/WindowModule/resources/"
    }
}