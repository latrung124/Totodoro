qt_add_library(userprofile_module STATIC)

qt_add_qml_module(
  userprofile_module
  URI
  UserProfileModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/UserProfileModule
  QML_FILES
  UserProfilePanel.qml
  RESOURCES
  "resources/default-avatar.png"
  "resources/language-button.png"
  "resources/question-button.png"
  "resources/settings-button.png")
