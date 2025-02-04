import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    objectName: "appWindow"
    visible: true
    width: 1366
    height: 780
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: function() {
        x = (screen.width - width) / 2;
        y = (screen.height - height) / 2;
    }

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: "#000000"
        opacity: 1
        radius: 8
        border {
            color: "#ffffff"
            width: 0.5
        }
    }
}
