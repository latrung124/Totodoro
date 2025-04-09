/*
* File: RoundedRectangle.qml
* Author: trung.la
* Date: 04-10-2025
* Description: This file contains the RoundedRectangle QML component, which is used to create a rounded rectangle shape.
*/

import QtQuick 2.15

// RoundedRectangle.qml
// This QML component creates a rounded rectangle shape using the Canvas element.
// Individual control over which corners are rounded
// Adjustable corner radius
// Customizable fill color
// Customizable border color and width

Item {
    id: root

    // Properties to control which corners are rounded
    property bool roundTopLeft: true
    property bool roundTopRight: true
    property bool roundBottomLeft: true
    property bool roundBottomRight: true

    // Corner radius value
    property real radius: 10

    // Rectangle styling properties
    property color fillColor: "#ffffff"
    property color borderColor: "#ffffff"
    property real borderWidth: 1

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var x = borderWidth / 2;
            var y = borderWidth / 2;
            var width = root.width - borderWidth;
            var height = root.height - borderWidth;
            var r = root.radius;

            // Begin the path
            ctx.beginPath();

            // Top left corner
            if (root.roundTopLeft) {
                ctx.moveTo(x, y + r);
                ctx.arcTo(x, y, x + r, y, r);
            } else {
                ctx.moveTo(x, y);
            }

            // Top right corner
            if (root.roundTopRight) {
                ctx.lineTo(x + width - r, y);
                ctx.arcTo(x + width, y, x + width, y + r, r);
            } else {
                ctx.lineTo(x + width, y);
            }

            // Bottom right corner
            if (root.roundBottomRight) {
                ctx.lineTo(x + width, y + height - r);
                ctx.arcTo(x + width, y + height, x + width - r, y + height, r);
            } else {
                ctx.lineTo(x + width, y + height);
            }

            // Bottom left corner
            if (root.roundBottomLeft) {
                ctx.lineTo(x + r, y + height);
                ctx.arcTo(x, y + height, x, y + height - r, r);
            } else {
                ctx.lineTo(x, y + height);
            }

            // Close the path
            if (root.roundTopLeft) {
                ctx.lineTo(x, y + r);
            } else {
                ctx.lineTo(x, y);
            }

            // Fill and stroke the path
            ctx.fillStyle = root.fillColor;
            ctx.fill();

            if (root.borderWidth > 0) {
                ctx.lineWidth = root.borderWidth;
                ctx.strokeStyle = root.borderColor;
                ctx.stroke();
            }
        }
    }

    // Update the canvas when properties change
    onRadiusChanged: canvas.requestPaint()
    onRoundTopLeftChanged: canvas.requestPaint()
    onRoundTopRightChanged: canvas.requestPaint()
    onRoundBottomLeftChanged: canvas.requestPaint()
    onRoundBottomRightChanged: canvas.requestPaint()
    onFillColorChanged: canvas.requestPaint()
    onBorderColorChanged: canvas.requestPaint()
    onBorderWidthChanged: canvas.requestPaint()
    onWidthChanged: canvas.requestPaint()
    onHeightChanged: canvas.requestPaint()
}
