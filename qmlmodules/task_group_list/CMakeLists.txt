qt_add_library(task_group_list_module STATIC)

target_link_libraries(task_group_list_module PRIVATE Qt6::Core5Compat)

qt_add_qml_module(
  task_group_list_module
  URI
  TaskGroupListModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/TaskGroupListModule
  QML_FILES
  TaskGroupListPanel.qml
  TaskGroupListTitlePanel.qml
  TaskGroupProgressBar.qml
  TaskGroupItem.qml
  RESOURCES
  "resources/icon/calendar.svg"
  "resources/icon/demon.png")
