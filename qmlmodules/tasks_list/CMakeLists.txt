qt_add_library(tasks_list_module STATIC)

target_link_libraries(tasks_list_module PRIVATE Qt6::Core5Compat)

qt_add_qml_module(
  tasks_list_module
  URI
  TasksListModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/TasksListModule
  QML_FILES
  TaskItem.qml
  TasksListView.qml
  TasksListPanel.qml
  OverlayedImage.qml
  RESOURCES
  "resources/icon/flag.svg"
  "resources/icon/completed.svg"
  "resources/priority/lowest.svg"
  "resources/priority/low.svg"
  "resources/priority/medium.svg"
  "resources/priority/high.svg"
  "resources/priority/highest.svg")
