/*
* File: PomodoroButton.qml
* Author: trung.la
* Date: 04-14-2025
* Description: PomodoroButton.qml is a QML file that defines the user interface for a Pomodoro button.
*/

import QtQuick

Item {
    id: root

    property bool hoverred: false
    property bool pressed: false
    property int buttonType: PomodoroButtonUnits.PomodoroButtonState.Start

    signal start()
    signal pause()
    signal resume()
    signal reset()

    onReset: {
        root.buttonType = PomodoroButtonUnits.PomodoroButtonState.Start;
        text.text = "Start";
        root.start();
    }

    implicitWidth: 109
    implicitHeight: 42

    Rectangle {
        id: background

        anchors.fill: parent
        color: "#ff2727"
        radius: 10
    }

    Text {
        id: text

        width: parent.width
        height: parent.height

       verticalAlignment: Text.AlignVCenter
       horizontalAlignment: Text.AlignHCenter

        font {
            family: "Onest"
            pixelSize: 14
            weight: Font.Bold
            letterSpacing: 0
        }

        color: "#ffffff"
        lineHeight: 1.0
        lineHeightMode: Text.FixedHeight
        text: qsTr("Start")
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true

        onPressed: root.pressed = true
        onReleased: root.pressed = false
        onEntered: root.hoverred = true
        onExited: {
            root.hoverred = false;
            root.pressed = false;
        }

        onClicked: {
            internal.setButtonState();
        }
    }

    states: [
        State {
            name: "hovered"
            when: root.hoverred && !root.pressed

            PropertyChanges {
                target: root
                opacity: 0.8
            }
        },

        State {
            name: "pressed"
            when: root.pressed && root.hoverred

            PropertyChanges {
                target: root
                opacity: 0.5
            }
        }
    ]

    QtObject {
        id: internal

        function setButtonState() {
            if (root.buttonType === PomodoroButtonUnits.PomodoroButtonState.Start) {
                root.buttonType = PomodoroButtonUnits.PomodoroButtonState.Pause;
            } else if (root.buttonType === PomodoroButtonUnits.PomodoroButtonState.Pause) {
                root.buttonType = PomodoroButtonUnits.PomodoroButtonState.Resume;
            } else {
                root.buttonType = PomodoroButtonUnits.PomodoroButtonState.Pause;
            }

            switch (root.buttonType) {
            case PomodoroButtonUnits.PomodoroButtonState.Start: {
                text.text = "Start";
                root.start();
                break;
            }
            case PomodoroButtonUnits.PomodoroButtonState.Pause: {
                text.text = "Pause";
                root.pause();
                break;
            }
            case PomodoroButtonUnits.PomodoroButtonState.Resume: {
                text.text = "Resume";
                root.resume();
                break;
            }
            default:
                text.text = "Start";
                break;
            }
        }
    }
}
