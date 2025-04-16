/*
* File: Window.qml
* Author: michael.godfrey
* Date: 04-03-2025
* Description: This file contains the Window QML component, which is used to create a window with a title bar and a close button.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CommonModule 1.0

Window {
    id: root

    width: internal.windowWidth
    height: internal.windowHeight

    visible: true
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: internal.setWindowCenterPos()

    ListModel {
        id: menuModel

        ListElement {
            text: ""
            iconSource: "qrc:/qt/qml/WindowModule/resources/home-button.png"
            iconColor: "#ffffff"
            isShowIcon: true
            isShowBackground: false
            toolTipText: "Home"
        }

        ListElement {
            text: ""
            iconSource: "qrc:/qt/qml/WindowModule/resources/statistics-button.png"
            iconColor: "#ffffff"
            isShowIcon: true
            isShowBackground: false
            toolTipText: "Statistics"
        }
    }

    Rectangle {
        id: backgroundRect

        anchors.fill: parent
        color: internal.bgDefaultColor
        opacity: 1
        radius: internal.radius
    }

    WindowDragger {
        id: dragArea

        width: parent.width
        height: 96
        anchors.top: parent
        dragTarget: root
        enableDrag: true
    }

    RowLayout {
        id: titleBar

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            topMargin: 24
            leftMargin: 40
            rightMargin: 40
        }

        height: 48

        RowLayout {
            id: titleBarContent

            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            Layout.preferredWidth: 162
            Layout.fillHeight: true

            spacing: 42

            Item {
                id: appNameItem

                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                Layout.preferredWidth: 48
                Layout.fillHeight: true

                Image {
                    id: appNameImage

                    anchors.fill: parent
                    source: `resources/app-name.png`
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                }
            }

            MenuTabs {
                id: bar

                Layout.alignment: Qt.AlignVCenter
                Layout.preferredWidth: 72
                Layout.preferredHeight: internal.titleBarBtnSize
                currentIndex: 0

                backgroundColor: "transparent"

                tabSpacing: internal.tabSpacing
                tabModels: menuModel
            }
        }

        WindowControl {
            id: windowControl

            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.preferredWidth: 104
            Layout.preferredHeight: internal.titleBarBtnSize

            spacing: 16

            onMinimizeWindow: function() {
                minimizeAnimation.start();
            }

            onCloseWindow: function() {
                navigator.closeWindow();
                close();
            }
        }
    }

    StackLayout {
        id: stackLayout

        anchors {
            top: titleBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            leftMargin: internal.contentLayoutMargin
            rightMargin: internal.contentLayoutMargin
            bottomMargin: internal.contentLayoutMargin
        }

        currentIndex: bar.currentIndex

        DialogFrameView {
            id: homeTab

            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true

            triangleXCenter: internal.calculateTabBarXCenter(0)

            loaderComponent: homeTabComponent

            Component {
                id: homeTabComponent

                WHomeTabLayout {
                    id: homeTabLayout

                    width: internal.tabWidth
                    height: internal.tabHeight

                    radius: homeTab.radius
                }
            }
        }

        DialogFrameView {
            id: statisticsTab

            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true

            triangleXCenter: internal.calculateTabBarXCenter(1)
        }
    }

    SequentialAnimation {
        id: minimizeAnimation
        ParallelAnimation {
            NumberAnimation { target: root; property: "x"; to: internal.hidePosX; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "y"; to: internal.hidePosY; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "width"; to: internal.hideWidthTarget; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "height"; to: internal.hideHeightTarget; duration: 200; easing.type: Easing.InOutQuad }
        }

        onFinished: function() {
            root.visibility = Window.Minimized;
            root.width = internal.windowWidth;
            root.height = internal.windowHeight;
            internal.setWindowCenterPos();
        }
    }

    QtObject {
        id: internal

        property int windowWidth: 1360
        property int windowHeight: 780
        property int radius: 20
        property int hidePosX: Math.floor(Screen.width / 2) - 50
        property int hidePosY: screen.height - 100
        property int hideWidthTarget: 100
        property int hideHeightTarget: 100
        property int minimizeDuration: 200

        readonly property color enableColor: "#ffffff"
        readonly property color disableColor: "#666666"
        readonly property color bgDefaultColor: "#222222"

        readonly property int tabWidth: 1328
        readonly property int tabHeight: 668
        readonly property int tabSpacing: 24
        readonly property int contentLayoutMargin: 16
        readonly property int titleBarBtnSize: 24

        readonly property string resourcePath: "qrc:/qt/qml/WindowModule/resources/"

        function setWindowCenterPos() {
            root.x = (screen.width - width) / 2;
            root.y = (screen.height - height) / 2;
        }

        function calculateTabBarXCenter(index) {
            const tabCount = menuModel.count;
            const totalSpacing = (tabCount - 1) * bar.tabSpacing;
            const tabWidth = (bar.width - totalSpacing) / tabCount;

            const triangleOffset = (homeTab.triangleWidth - tabWidth) / 2;

            const baseX = bar.x + titleBar.x;
            const tabX = index * (tabWidth + bar.tabSpacing);
            const centerOffset = tabWidth / 2;

            return baseX + tabX + centerOffset - triangleOffset;
        }
    }
}
