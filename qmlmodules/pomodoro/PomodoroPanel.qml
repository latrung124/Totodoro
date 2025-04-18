/*
* File: PomodoroPanel.qml
* Author: trung.la
* Date: 04-11-2025
* Description: PomodoroPanel.qml is a QML file that defines the user interface for a Pomodoro timer application.
* It includes a timer display, start/pause button, and reset button. The timer can be customized with different durations for work and break periods. The UI is designed to be simple and user-friendly, allowing users to easily manage their work sessions and breaks.
*/

import QtQuick
import QtQuick.Layouts

import CommonModule 1.0

Item {
    id: root

    property alias backgroundColor: background.color

    implicitWidth: 580
    implicitHeight: 586

    Rectangle {
        id: background

        anchors.fill: parent
        color: internal.backgroundColor
    }

    ColumnLayout {
        id: layout

        anchors {
            fill: parent
            leftMargin: 24
            rightMargin: 24
            bottomMargin: 24
        }

        spacing: 5

        RowLayout {
            id: titleLayout

            Layout.fillWidth: true
            Layout.preferredHeight: 74

            spacing: 8

            Item {
                Layout.preferredWidth: 32
                Layout.preferredHeight: 32
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                Image {
                    id: titleIcon

                    width: parent.width
                    height: parent.height
                    source: 'resources/flag.png'
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    asynchronous: true
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 32
                Layout.alignment: Qt.AlignVCenter

                Text {
                    id: textTitle

                    width: parent.width
                    height: parent.height

                    anchors {
                        left: parent.left
                        verticalCenter: parent.verticalCenter
                    }

                    verticalAlignment: Text.AlignVCenter

                    font {
                        family: "Onest"
                        pixelSize: 26
                        weight: Font.Bold
                        letterSpacing: 0

                    }

                    lineHeight: 1.0
                    lineHeightMode: Text.FixedHeight
                    text: qsTr("Lesson 7")
                }
            }
        }

        ColumnLayout {
            id: pomodoroLayout

            Layout.fillWidth: true
            Layout.fillHeight: true

            spacing: 10

            ColumnLayout {
                id: detailInfoLayout

                Layout.fillWidth: true
                Layout.preferredHeight: 50
                
                spacing: 8

                RowLayout {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 24
                    Layout.alignment: Qt.AlignTop

                    spacing: 4

                    Item {
                        id: clockIconItem

                        Layout.preferredWidth: 24
                        Layout.preferredHeight: 24
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                        Image {
                            id: clockIcon

                            width: parent.width
                            height: parent.height
                            source: 'resources/square-clock.png'
                            fillMode: Image.PreserveAspectFit
                            smooth: true
                            asynchronous: true
                        }
                    }

                    Item {
                        id: clockTimeTextItem

                        Layout.preferredWidth: 65 // TODO: need refactor to 57px when the Onest font is updated
                        Layout.preferredHeight: 24
                        Layout.alignment: Qt.AlignVCenter

                        Text {
                            id: clockTimeText

                            width: parent.width
                            height: parent.height

                            anchors {
                                left: parent.left
                                verticalCenter: parent.verticalCenter
                            }
                            verticalAlignment: Text.AlignVCenter

                            font {
                                family: "Onest"
                                pixelSize: 14
                                weight: Font.Bold
                                letterSpacing: 0
                            }

                            lineHeight: 1.0
                            lineHeightMode: Text.FixedHeight
                            text: qsTr("04:24:14")
                        }
                    }

                    Item {
                        id: circleSpacing

                        Layout.preferredWidth: 4
                        Layout.preferredHeight: 4
                        Layout.alignment: Qt.AlignVCenter

                        Rectangle {
                            anchors.fill: parent
                            radius: 2
                            color: "#000000"
                        }
                    }

                    Row {
                        id: countedObjectRow

                        Layout.fillWidth: true
                        Layout.preferredHeight: 24
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 0

                        Repeater {
                            id: countedObjectlv4

                            model: 2 // TODO: refactor with real model

                            Item {
                                id: countedObject

                                width: 29
                                height: 24

                                Image {
                                    id: countedObjectImg

                                    width: parent.width
                                    height: parent.height
                                    source: 'resources/monster-level-4.png'
                                    fillMode: Image.PreserveAspectFit
                                    smooth: true
                                }
                            }
                        }
                    }
                }

                Item {
                    id: descriptionTextItem
                    Layout.fillWidth: true
                    Layout.preferredHeight: 18

                    Text {
                        id: descriptionText

                        width: parent.width
                        height: parent.height

                        anchors {
                            left: parent.left
                            verticalCenter: parent.verticalCenter
                        }
                        verticalAlignment: Text.AlignVCenter

                        font {
                            family: "Onest"
                            pixelSize: 14
                            weight: Font.Normal
                            letterSpacing: 0
                        }

                        color: "#7f7f7f"
                        lineHeight: 1.0
                        lineHeightMode: Text.FixedHeight
                        text: qsTr("Learn Chinese HSK 5!!!")
                    }
                }
            }
        }

        ColumnLayout {
            id: pomodoroContent

            Layout.fillWidth: true
            Layout.fillHeight: true

            spacing: 40

            Item {
                id: dynamicObjectRec

                Layout.fillWidth: true
                Layout.preferredHeight: 247

                Image {
                    id: dynamicObjectImg

                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        bottom: parent.bottom
                    }

                    source: 'resources/monster-level-1.png'
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    asynchronous: true
                }
            }

            Item {
                id: pomodoroButtonItem

                Layout.fillWidth: true
                Layout.preferredHeight: 42

               PomodoroButton {
                    id: pomodoroButton

                    height: parent.height
                    anchors {
                        left: parent.left
                        right: parent.right
                        verticalCenter: parent.verticalCenter
                        leftMargin: 212
                        rightMargin: 212
                    }

                    onStart: {
                        internal.timerStop();
                    }

                    onPause: {
                        internal.timerStart();
                    }

                    onResume: {
                        internal.timerPause();
                    }
                }
            }

            Item {
                id: progressBarItem
                Layout.fillWidth: true
                Layout.preferredHeight: 68


                Item {
                    id: progressLocItem

                    width: 24
                    height: 24
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: -9
                    }

                    Image {
                        id: progressLocation

                        width: parent.width
                        height: parent.height
                        source: 'resources/location.png'
                        fillMode: Image.PreserveAspectFit
                        smooth: true
                        asynchronous: true
                        x: progressBar.visualPosition * progressBar.width

                        NumberAnimation on x {
                            duration: 1000
                            easing.type: Easing.InOutQuad
                        }
                    }
                }

                PomodoroProgressBar {
                    id: progressBar

                    anchors {
                        left: parent.left
                        right: parent.right
                        top: parent.top
                        bottom: parent.bottom
                        topMargin: 30
                        bottomMargin: 26
                    }
                    value: 0
                }

                Item {
                    id: bottomProgressValueItem

                    height: 18
                    anchors {
                        left: parent.left
                        right: parent.right
                        bottom: parent.bottom
                    }

                    Item {
                        id: pomodoroTextItem

                        width: 69
                        height: parent.height
                        anchors {
                            left: parent.left
                            verticalCenter: parent.verticalCenter
                        }

                        Text {
                            id: pomodoroText

                            width: parent.width
                            height: parent.height

                            anchors {
                                left: parent.left
                                verticalCenter: parent.verticalCenter
                            }
                            verticalAlignment: Text.AlignVCenter

                            font {
                                family: "Onest"
                                pixelSize: 14
                                weight: Font.Bold
                                letterSpacing: 0
                            }

                            color: "#000000"
                            lineHeight: 1.0
                            lineHeightMode: Text.FixedHeight
                            text: qsTr("Pomodoro")
                        }
                    }

                    Item {
                        id: progressValueItem

                        width: 63
                        height: parent.height

                        anchors {
                            right: parent.right
                            verticalCenter: parent.verticalCenter
                        }

                        Text {
                            id: progressValueText

                            width: parent.width
                            height: parent.height

                            anchors {
                                left: parent.left
                                verticalCenter: parent.verticalCenter
                            }
                            verticalAlignment: Text.AlignVCenter

                            font {
                                family: "Onest"
                                pixelSize: 14
                                weight: Font.Bold
                                letterSpacing: 0
                            }

                            color: "#000000"
                            lineHeight: 1.0
                            lineHeightMode: Text.FixedHeight
                            text: qsTr("03:00:00")
                        }
                    }
                }
            }
        }
    }

    Timer {
        id: pomodoroTimer

        running: false
        repeat: true
        interval: internal.defaultDuration
        onTriggered: {
            if (progressBar.value === 1) {
                pomodoroButton.reset();
                return;
            }

            internal.currentTime += internal.defaultDuration;
            progressBar.value = internal.currentTime / (internal.defaultPomodoroTime * internal.defaultDuration);
        }
    }

    QtObject {
        id: internal

        readonly property color backgroundColor: "#ffffff"
        readonly property color textDefaultColor: "#000000"
        readonly property int defaultPomodoroTime: 1500 // 25m
        readonly property int defaultDuration: 1000 // 1s
        property int currentTime: 0

        // Timer Start, Pause and Stop function
        function timerStart() {
            pomodoroTimer.start();
        }

        function timerPause() {
            pomodoroTimer.stop();
        }

        function timerStop() {
            pomodoroTimer.running = false;
            progressBar.value = 0;
            internal.currentTime = 0;
        }
    }
}
