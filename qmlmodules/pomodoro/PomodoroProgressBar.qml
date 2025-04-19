/*
* File: PomodoroProgressBar.qml
* Author: trung.la
* Date: 04-18-2025
* Description: This file contains the Pomodoro Progress Bar QML component for window,
*/

/*
* File: PomodoroProgressBar.qml
* Author: trung.la
* Date: 04-17-2025
* Description: This file contains the PomodoroProgressBar component which is used to show the progress of the Pomodoro task.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Templates as T

T.ProgressBar {
    id: control

    property alias backgroundColor: background.color
    property alias backgroundRadius: background.radius

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
        implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
        implicitContentHeight + topPadding + bottomPadding)

    background: Rectangle {
        id: background

        implicitWidth: internal.defaultWidth
        implicitHeight: internal.defaultHeight
        color: internal.defaultBackgroundColor
        radius: internal.defaultRadius
    }

    contentItem: Item {
        id: indicatorItem

        implicitWidth: internal.defaultWidth
        implicitHeight: internal.defaultHeight

        Rectangle {
            id: indicator

            width: control.visualPosition * parent.width
            height: internal.defaultHeight
            color: internal.defaultProgressColor
            radius: internal.defaultRadius

            NumberAnimation on width {
                duration: internal.defaultDuration
                easing.type: Easing.InOutQuad
            }
        }
    }

    QtObject {
        id: internal

        readonly property int defaultHeight: 12
        readonly property int defaultWidth: 532
        readonly property int defaultRadius: 4
        readonly property int defaultDuration: 1000
        readonly property color defaultBackgroundColor: "#d9d9d9"
        readonly property color defaultProgressColor: "#222222"
    }
}
