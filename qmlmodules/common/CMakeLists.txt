qt_add_library(common_module STATIC)

target_link_libraries(common_module PRIVATE Qt6::Core5Compat)

set(image_components images/RoundedImage.qml)

set(button_components
    buttons/CustomButton.qml buttons/CustomButtonBackground.qml
    buttons/CustomButtonContent.qml)

foreach(button ${button_components})
  get_filename_component(component_name ${button} NAME)
  set_source_files_properties(${button} PROPERTIES QT_RESOURCE_ALIAS
                                                   ${component_name})
endforeach()

foreach(image ${image_components})
  get_filename_component(component_name ${image} NAME)
  set_source_files_properties(${image} PROPERTIES QT_RESOURCE_ALIAS
                                                  ${component_name})
endforeach()

qt_add_qml_module(
  common_module
  URI
  CommonModule
  VERSION
  1.0
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/CommonModule
  QML_FILES
  WindowControl.qml
  buttons/CustomButton.qml
  buttons/CustomButtonBackground.qml
  buttons/CustomButtonContent.qml
  images/RoundedImage.qml
  RESOURCES
  "resources/window/close-button.png"
  "resources/window/maximize-button.png"
  "resources/window/minimize-button.png"
  "resources/media/music-note.png")
