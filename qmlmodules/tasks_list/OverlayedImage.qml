/*
* File: OverlayedImage.qml
* Author: dang.nguyen
* Date: 04-04-2025
* Brief: This file contains the OverlayedImage component which is used to control the window of the application.
*/

import QtQuick
import Qt5Compat.GraphicalEffects

Item {
	id: root

	property alias source: image.source
	property alias color: colorOverlay.color

	implicitWidth: image.width
	implicitHeight: image.height

	Image {
		id: image

		visible: false
		smooth: true
		fillMode: Image.PreserveAspectFit
	}

	ColorOverlay {
		id: colorOverlay

		anchors.fill: image
		source: image
	}
}
