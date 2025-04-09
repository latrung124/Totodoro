/*
* File: DialogFrameView.qml
* Author: trung.la
* Date: 04-08-2025
* Description: This file contains the FrameView QML component, which is used to create a frame view for the application.
*/

import QtQuick

Item {
    id: root

    property double verticalOffset: 23.5
    property double radius: 12
    property int triangleWidth: 36
    property int triangleHeight: 15
    property int triangleXCenter: radius + triangleWidth / 2
    property color frameColor: "#efefef"
    property QtObject loaderComponent: null

    property alias loaderSource: componentLoader.source
    property alias loaderWidth: componentLoader.width
    property alias loaderHeight: componentLoader.height

    implicitWidth: 1328
    implicitHeight: 692

    Canvas {
        id: mycanvas

        anchors.fill: parent

        onPaint: {
            const ctx = getContext("2d");                        // Get 2D context
            ctx.clearRect(0, 0, width, height);                  // Clear canvas

            const translateY = root.verticalOffset;              // New vertical offset
            const radius = root.radius;                          // Radius for rounded corners
            const triangleWidth = root.triangleWidth;            // Width of the triangle
            const triangleHeight = root.triangleHeight;          // Height of the triangle
            const triangleX = root.triangleXCenter;              // X center of triangle
            const color = root.frameColor

            const adjustedHeight = height - translateY;          // Bottom of shape after vertical shift

            ctx.save();                                          // Save context
            ctx.translate(0.5, translateY);                      // Apply translation, keep attention below

            // === Remind when modify translateY ===
            // A blurred top line in canvas drawing (especially in HTML5/QtQuick Canvas)
            // usually happens due to sub-pixel rendering, often caused by drawing on a non-integer pixel boundary.
            // When a line falls between two pixels, the renderer antialiases it—making it appear soft or blurry.
            // If you’re using lineWidth = 1, always try to draw lines at .5 coordinates
            // so they align perfectly within the pixel grid.

            ctx.beginPath();

            // === Top line and triangle ===
            ctx.moveTo(radius, 0);
            if (triangleX - triangleWidth / 2 > radius) {
                ctx.lineTo(triangleX - triangleWidth / 2, 0);   // Left of triangle base
            }

            ctx.lineTo(triangleX, -triangleHeight);             // Triangle tip
            ctx.lineTo(triangleX + triangleWidth / 2, 0);       // Right of triangle base

            ctx.lineTo(width - radius, 0);
            ctx.quadraticCurveTo(width, 0, width, radius);      // Top-right corner

            // === Right side ===
            ctx.lineTo(width, adjustedHeight - radius);
            ctx.quadraticCurveTo(width, adjustedHeight, width - radius, adjustedHeight); // Bottom-right corner

            // === Bottom ===
            ctx.lineTo(radius, adjustedHeight);
            ctx.quadraticCurveTo(0, adjustedHeight, 0, adjustedHeight - radius);         // Bottom-left corner

            // === Left side ===
            ctx.lineTo(0, radius);
            ctx.quadraticCurveTo(0, 0, radius, 0);             // Top-left corner

            ctx.closePath();

            // === Fill & Stroke ===
            ctx.fillStyle = color;
            ctx.fill();

            ctx.strokeStyle = color;
            ctx.lineWidth = 1;
            ctx.stroke();

            ctx.restore(); // Restore state
        }

        Component.onCompleted: requestPaint()
    }

    Loader {
        id: componentLoader

        anchors {
            top: parent.top
            topMargin: root.verticalOffset
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }

        sourceComponent: root.loaderComponent
    }
}
