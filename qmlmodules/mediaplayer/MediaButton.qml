/*
* File: MediaButton.qml
* Author: michael.godfrey
* Date: 04-20-2025
* Description: This file contains the MediaButton component which is used to create a button for media control.
*/

import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Templates as T

T.Button {
    id: control

    property color basicColor: "#ffffff"
    property color accentColor: "#000000"
    property int buttonForm: MediaEnumeration.ButtonForm.None

    signal buttonClicked(form: int)

    onButtonFormChanged: {
        internal.setButtonResourceForm(control.buttonForm);
    }

    implicitWidth: Math.max(background.implicitWidth + leftInset + rightInset,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background.implicitHeight + topInset + bottomInset,
                            contentItem.implicitHeight + topPadding + bottomPadding)

    ToolTip.visible: hovered
    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval

    contentItem: Item {
        id: contentItem

        width: 24
        height: 24
        anchors.centerIn: parent

        Image {
            id: icon

            anchors.fill: parent
            source: internal.setButtonResourceForm(control.buttonForm)
            fillMode: Image.PreserveAspectFit
        }

        ColorOverlay {
            id: iconOverlay

            anchors.fill: icon
            source: icon
            color: control.basicColor
        }
    }

    background: Rectangle {
        id: background

        anchors.fill: parent
        color: control.basicColor
        opacity: control.buttonForm === MediaEnumeration.ButtonForm.Play ? 1.0 : 0.0
        radius: 5
        visible: control.buttonForm === MediaEnumeration.ButtonForm.Play
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: {
            control.buttonClicked(control.buttonForm);
        }
    }

    states: [
        State {
            name: "hovered"
            when: !mouseArea.pressed && mouseArea.containsMouse && control.enabled
            PropertyChanges {
                target: contentItem
                opacity: 0.8
            }

            PropertyChanges {
                target: background
                opacity: 0.8
            }
        },
        State {
            name: "pressed"
            when: mouseArea.pressed && mouseArea.containsMouse &&  control.enabled
            PropertyChanges {
                target: contentItem
                opacity: 0.5
            }

            PropertyChanges {
                target: background
                opacity: 0.8
            }
        },
        State {
            name: "backgroundVisible"
            when: buttonForm === MediaEnumeration.ButtonForm.Play
            PropertyChanges {
                target: background
                opacity: 1.0
            }
        },
        State {
            name: "backgroundInvisible"
            when: buttonForm === MediaEnumeration.ButtonForm.Pause
            PropertyChanges {
                target: background
                opacity: 0.0
            }
        },
        State {
            name: "disabled"
            when: !control.enabled
            PropertyChanges {
                target: contentItem
                opacity: 0.5
            }
        }
    ]

    transitions: [
        Transition {
            from: "backgroundInvisible"
            to: "backgroundVisible"
            NumberAnimation {
                properties: "opacity"
                duration: 200
            }
        },
        Transition {
            from: "backgroundVisible"
            to: "backgroundInvisible"
            NumberAnimation {
                properties: "opacity"
                duration: 200
            }
        }
    ]

    QtObject {
        id: internal

        function setButtonResourceForm(form) {
            switch (form) {
                case MediaEnumeration.ButtonForm.None:
                    icon.source = "";
                    break;
                case MediaEnumeration.ButtonForm.Play: {
                    iconOverlay.color = control.accentColor;
                    icon.source = "resources/play-button.png";
                    break;
                }
                case MediaEnumeration.ButtonForm.Pause: {
                    iconOverlay.color = control.basicColor;
                    icon.source = "resources/pause-button.png";
                    break;
                }
                case MediaEnumeration.ButtonForm.Next:
                    icon.source = "resources/next-button.png";
                    break;
                case MediaEnumeration.ButtonForm.Previous:
                    icon.source = "resources/previous-button.png";
                    break;
                case MediaEnumeration.ButtonForm.Shuffle:
                    icon.source = "resources/shuffle-button.png";
                    break;
                case MediaEnumeration.ButtonForm.Repeat:
                    icon.source = "resources/repeat-button.png";
                    break;
                case MediaEnumeration.ButtonForm.Sound:
                    icon.source = "resources/sound-button.png";
                    break;
            }
        }
    }
}
