/*
* File: WindowDragArea.qml
* Author: trung.la
* Date: 04-06-2025
* Description: This file contains the WindowDragArea component which is used to create a drag area for the window.
* It allows the user to drag the window around the screen by clicking and dragging on the area.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Window

Item {
    id: dragArea

    property var dragTarget: null   // Set to a Window, Popup, or Item
    property bool enableDrag: true  // Whether dragging is enabled
    property bool dragX: true       // Allow horizontal drag
    property bool dragY: true       // Allow vertical drag

    implicitWidth: 100
    implicitHeight: 100

    DragHandler {
        id: dragHandler
        enabled: enableDrag
        acceptedDevices: PointerDevice.AllDevices
        grabPermissions: PointerHandler.CanTakeOverFromItems | PointerHandler.CanTakeOverFromHandlersOfDifferentType | PointerHandler.ApprovesTakeOverByAnything

        onActiveChanged: {
            if (!active || !dragTarget)
                return;

            if (dragTarget instanceof Window) {
                dragTarget.startSystemMove();
            } else if (dragTarget instanceof Popup) {
                dragTarget.x += translation.x;
                dragTarget.y += translation.y;
            } else if (dragTarget instanceof Item) {
                dragTarget.x += translation.x;
                dragTarget.y += translation.y;
            }
        }

        xAxis.enabled: dragX
        yAxis.enabled: dragY
    }
}