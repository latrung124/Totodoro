/*
* File: RoundedImage.qml
* Author: trung.la
* Date: 02-04-2025
* Brief: This file contains the RoundedImage component which is used to display an image with rounded corners.
*/

import QtQuick
import Qt5Compat.GraphicalEffects

Item {
    id: root

    property string imageSource: ""
    property int imageRoundRadius: 2
    property int imageWidth: 60
    property int imageHeight: 60
    property alias backgroundRoundRadius: backgroundRect.radius
    property alias backgroundColor: backgroundRect.color
    property alias borderColor: backgroundRect.border.color

    implicitWidth: 80
    implicitHeight: 80

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#000000"
        radius: 4

        border {
            color: "#ffffff"
            width: imageRoundRadius/2
        }

        Image {
            id: image

            width: imageWidth - imageRoundRadius
            height: imageHeight- imageRoundRadius
            anchors.centerIn: parent
            source: imageSource === "" ? `resources/media/music-note.png` : imageSource
            fillMode: Image.PreserveAspectFit
            cache: false
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: Item {
                    width: image.width
                    height: image.height
                    Rectangle {
                        anchors.centerIn: parent
                        width: image.width
                        height: image.height
                        radius: imageRoundRadius
                    }
                }
            }
        }
    }
}