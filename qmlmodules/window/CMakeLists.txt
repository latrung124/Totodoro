qt_add_library(window_module STATIC)

set(window_components
    MainWindow.qml)

foreach(window ${window_components})
  get_filename_component(component_name ${window} NAME)
  set_source_files_properties(${window} PROPERTIES QT_RESOURCE_ALIAS
                                                   ${component_name})
endforeach()

qt_add_qml_module(
  window_module
  URI
  WindowModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/WindowModule
  QML_FILES
  window-components/MainWindow.qml
  RESOURCES
  "resources/close-button.png"
  "resources/maximize-button.png"
  "resources/minimize-button.png")