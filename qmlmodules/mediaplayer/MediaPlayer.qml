/*
* File: MediaPlayer.qml
* Author: trung.la
* Author: michael.godfrey
* Date: 02-04-2025
* Brief: This file contains the WindowControl component which is used to control the window of the application.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    property color basicColor: "#ffffff"

    implicitWidth: 406
    implicitHeight: 48

    Rectangle {
        id: background // TODO: change to default artwork

        anchors.fill: parent
        color: "transparent"
        border.color: root.basicColor
        radius: 10
    }

    RowLayout {
        id: layout

        anchors {
            fill: parent
            leftMargin: 16
            rightMargin: 16
            topMargin: 7
            bottomMargin: 6
        }

        spacing: 30

        Item {
            Layout.preferredWidth: 133
            Layout.preferredHeight: 35
            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

            ColumnLayout {
                id: songInforColumn

                anchors.fill: parent

                spacing: 2

                Item {
                    id: songNameItem

                    Layout.fillWidth: true
                    Layout.preferredHeight: 18
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

                    Text {
                        id: songName

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

                        elide: Text.ElideRight
                        maximumLineCount: 1
                        lineHeight: 1.0
                        lineHeightMode: Text.FixedHeight
                        color: root.basicColor
                        text: qsTr("Legends Never Die")
                    }
                }

                Item {
                    id: songAlbumItem

                    Layout.fillWidth: true
                    Layout.preferredHeight: 15
                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

                    Text {
                        id: songAlbum

                        width: parent.width
                        height: parent.height

                        anchors {
                            left: parent.left
                            verticalCenter: parent.verticalCenter
                        }

                        verticalAlignment: Text.AlignVCenter

                        font {
                            family: "Onest"
                            pixelSize: 12
                            weight: Font.Light
                            letterSpacing: 0
                        }

                        elide: Text.ElideRight
                        maximumLineCount: 1
                        lineHeight: 1.0
                        lineHeightMode: Text.FixedHeight
                        color: root.basicColor
                        text: qsTr("Orchestral version")
                    }
                }
            }
        }

        Item {
            Layout.preferredWidth: 211
            Layout.preferredHeight: 32
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

            RowLayout {
                id: controlLayout

                anchors.fill: parent
                spacing: 27

                RowLayout {
                    id: playbackControl

                    Layout.preferredWidth: 160
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                    spacing: 8

                    MediaButton {
                        id: shuffleButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Shuffle
                        ToolTip.text: "Shuffle"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form);
                        }
                    }

                    MediaButton {
                        id: previousButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Previous
                        ToolTip.text: "Previous"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form);
                        }
                    }

                    MediaButton {
                        id: playPauseButton

                        Layout.preferredWidth: internal.defaultPlayPauseButtonSize
                        Layout.preferredHeight: internal.defaultPlayPauseButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        padding: 4
                        buttonForm: MediaEnumeration.ButtonForm.Play
                        ToolTip.text: playPauseButton.buttonForm === MediaEnumeration.ButtonForm.Play ? "Pause" : "Play"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form);
                        }
                    }

                    MediaButton {
                        id: nextButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Next
                        ToolTip.text: "Next"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form);
                        }
                    }

                    MediaButton {
                        id: repeatButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Repeat
                        ToolTip.text: "Repeat"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form);
                        }
                    }
                }

                MediaButton {
                    Layout.preferredWidth: internal.defaultButtonSize
                    Layout.preferredHeight: internal.defaultButtonSize
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    buttonForm: MediaEnumeration.ButtonForm.Sound
                    ToolTip.text: "Mute"
                    onButtonClicked: (form) => {
                        internal.handleMediaButtonClicked(form);
                    }
                }
            }
        }
    }

    QtObject {
        id: internal

        readonly property int defaultButtonSize: 24
        readonly property int defaultPlayPauseButtonSize: 32

        function handleMediaButtonClicked(form) {
            //TODO: implement model to handle these actions.
            switch (form) {
            case MediaEnumeration.ButtonForm.None:
                console.log("MediaEnumeration Invalid!")
                break
            case MediaEnumeration.ButtonForm.Play: {
                console.log("Play button clicked!")
                playPauseButton.buttonForm = MediaEnumeration.ButtonForm.Pause;
                break
            }
            case MediaEnumeration.ButtonForm.Pause: {
                console.log("Pause button clicked!")
                playPauseButton.buttonForm = MediaEnumeration.ButtonForm.Play;
                break
            }
            case MediaEnumeration.ButtonForm.Next:
                console.log("Next button clicked!")
                break
            case MediaEnumeration.ButtonForm.Previous:
                console.log("Previous button clicked!")
                break
            case MediaEnumeration.ButtonForm.Shuffle:
                console.log("Shuffle button clicked!")
                break
            case MediaEnumeration.ButtonForm.Repeat:
                console.log("Repeat button clicked!")
                break
            case MediaEnumeration.ButtonForm.Sound:
                console.log("Sound button clicked!")
                break
            }
        }
    }
}
