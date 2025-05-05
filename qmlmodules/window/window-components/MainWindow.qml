/*
* File: MainWindow.qml
* Author: michael.godfrey
* Date: 04-03-2025
* Description: This file contains the MainWindow QML component, which is used to create a window with a title bar and a close button.
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import CommonModule 1.0
import MediaPlayerModule 1.0

Window {
    id: root

    property QtObject model: null

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
        radius: internal.radius
    }

    WindowDragger {
        id: dragArea

        width: parent.width
        height: 96
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

        RowLayout {
            id: leftControlLayout

            Layout.preferredWidth: 340
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignRight
            spacing: 24

            MediaPlayer {
                id: mediaPlayer

                objectName: "mediaPlayer"

                Layout.preferredWidth: 406
                Layout.preferredHeight: 48
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            }

            RowLayout {
                id: buttonsControlLayout

                Layout.preferredWidth: 156
                Layout.preferredHeight: 38
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                spacing: 16

                WindowNotificationControl {
                    id: notificationControl

                    Layout.preferredWidth: 38
                    Layout.preferredHeight: 38
                    Layout.alignment: Qt.AlignRight
                }

                WindowControl {
                    id: windowControl

                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    Layout.preferredWidth: 104
                    Layout.preferredHeight: internal.titleBarBtnSize

                    spacing: 16

                    onMinimizeWindow: function() {
                        minimizedAnimation.running = true;
                    }

                    onMaximizeWindow: function() {
                        root.showMaximized();
                    }

                    onRestoreWindow: function() {
                        root.showNormal();
                    }

                    onCloseWindow: function() {
                        root.close();
                    }
                }
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

                    objectName: "homeView"

                    width: homeTab.width
                    height: homeTab.height

                    radius: homeTab.radius

                    onModelChanged: {
                        console.log("Home tab model changed")
                    }
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

        onCurrentIndexChanged: {
            console.log("Current index changed to: " + stackLayout.currentIndex);
            viewModelController.tabNavigation(stackLayout.currentIndex);
        }
    }

    NumberAnimation {
        id: minimizedAnimation

        target: root

        property: "opacity"
        to: 0.0
        duration: 250
        easing.type: Easing.InOutQuad

        onStopped: {
            root.showMinimized();
            root.opacity = 1.0;
        }
    }

    QtObject {
        id: internal

        property int windowWidth: 1360
        property int windowHeight: 780
        property int radius: windowControl.isMaximized ? 0 : 8

        readonly property color enableColor: "#ffffff"
        readonly property color disableColor: "#666666"
        readonly property color bgDefaultColor: "#222222"

        readonly property int tabSpacing: 24
        readonly property int contentLayoutMargin: 16
        readonly property int titleBarBtnSize: 24

        readonly property string resourcePath: "qrc:/qt/qml/WindowModule/resources/"

        function setWindowCenterPos() {
            root.x = (Screen.width - width) / 2;
            root.y = (Screen.height - height) / 2;
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
