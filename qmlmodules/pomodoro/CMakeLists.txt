qt_add_library(pomodoro_module STATIC)

qt_add_qml_module(
  pomodoro_module
  URI
  PomodoroModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/PomodoroModule
  QML_FILES
  PomodoroPanel.qml
  RESOURCES
  "resources/flag.png"
  "resources/flag2.png"
  "resources/location.png"
  "resources/monster-level-4.png"
  "resources/square-clock.png"
  "resources/monster-level-1.png")

