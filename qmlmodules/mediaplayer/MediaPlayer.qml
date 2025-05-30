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
    property QtObject model: null

    implicitWidth: 406
    implicitHeight: 48

    Rectangle {
        id: background // TODO: change to default artwork

        anchors.fill: parent
        color: "transparent"
        border.color: root.basicColor
        radius: 10
        border.width: 0.5

        Image {
            id: artwork

            anchors {
                fill: parent
                margins: 1
            }
            source: internal.defaultArtwork
            fillMode: Image.PreserveAspectFit
            smooth: true

            onStatusChanged: {
                if (artwork.status === Image.Error) {
                    console.log("Error loading image:", artwork.source);
                    // TODO: in case artwork was from model, we can used default artwork
                }
            }
        }
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
                        text: root.model ? root.model.title : "Unknown"
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
                        text: root.model ? root.model.album : "Unknown"
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

                    property QtObject playbackModel: root.model ? root.model.mediaPlaybackViewModel : null

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
                        enabled: playbackControl.playbackModel ? playbackControl.playbackModel.isShuffleEnabled : false
                        ToolTip.text: "Shuffle"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
                        }
                    }

                    MediaButton {
                        id: previousButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Previous
                        enabled: playbackControl.playbackModel ? playbackControl.playbackModel.isPreviousEnabled : false
                        ToolTip.text: "Previous"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
                        }
                    }

                    MediaButton {
                        id: playPauseButton

                        Layout.preferredWidth: internal.defaultPlayPauseButtonSize
                        Layout.preferredHeight: internal.defaultPlayPauseButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        padding: 4
                        buttonForm: internal.getPlayPauseButtonForm(playbackControl.playbackModel ? playbackControl.playbackModel.isPlaying : false)
                        enabled: internal.getPlayPauseButtonEnabled()
                        ToolTip.text: playPauseButton.buttonForm === MediaEnumeration.ButtonForm.Play ? "Pause" : "Play"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
                        }
                    }

                    MediaButton {
                        id: nextButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Next
                        enabled: playbackControl.playbackModel ? playbackControl.playbackModel.isNextEnabled : false
                        ToolTip.text: "Next"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
                        }
                    }

                    MediaButton {
                        id: repeatButton

                        Layout.preferredWidth: internal.defaultButtonSize
                        Layout.preferredHeight: internal.defaultButtonSize
                        Layout.alignment: Qt.AlignVCenter
                        buttonForm: MediaEnumeration.ButtonForm.Repeat
                        enabled: playbackControl.playbackModel ? playbackControl.playbackModel.isRepeatEnabled : false
                        ToolTip.text: "Repeat"
                        onButtonClicked: (form) => {
                            internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
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
                        internal.handleMediaButtonClicked(form, playbackControl.playbackModel);
                    }
                }
            }
        }
    }

    QtObject {
        id: internal

        readonly property int defaultButtonSize: 24
        readonly property int defaultPlayPauseButtonSize: 32
        readonly property string defaultArtwork: "resources/default-media-artwork.png"

        function getPlayPauseButtonForm(isPlaying) {
            if (isPlaying) {
                return MediaEnumeration.ButtonForm.Pause;
            } else {
                return MediaEnumeration.ButtonForm.Play;
            }
        }

        function getPlayPauseButtonEnabled() {
            var playbackModel = playbackControl.playbackModel;
            if (!playbackModel) {
                return false;
            }

            return playbackModel.isPlaying ? playbackModel.isPauseEnabled : playbackModel.isPlayingEnabled;
        }

        function handleMediaButtonClicked(form, model) {
            //TODO: implement model to handle these actions.
            switch (form) {
            case MediaEnumeration.ButtonForm.None:
                console.log("MediaEnumeration Invalid!")
                break
            case MediaEnumeration.ButtonForm.Play: {
                console.log("Play button clicked!")
                if (!model) {
                    console.log("playback view model is null!")
                }

                model.play();
                playPauseButton.buttonForm = MediaEnumeration.ButtonForm.Pause;
                break
            }
            case MediaEnumeration.ButtonForm.Pause: {
                console.log("Pause button clicked!")
                if (!model) {
                    console.log("playback view model is null!")
                }

                model.pause();
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
