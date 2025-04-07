qt_add_library(common_module STATIC)

target_link_libraries(common_module PRIVATE Qt6::Core5Compat)

set(image_components images/RoundedImage.qml)

set(button_components
    buttons/CustomButton.qml buttons/CustomButtonBackground.qml
    buttons/CustomButtonContent.qml)

set(dragger_components draggers/WindowDragger.qml)

set(menu_components menus/MenuTab.qml menus/MenuTabs.qml)

set(view_components views/DialogFrameView.qml)

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

foreach(dragger ${dragger_components})
  get_filename_component(component_name ${dragger} NAME)
  set_source_files_properties(${dragger} PROPERTIES QT_RESOURCE_ALIAS
                                                    ${component_name})
endforeach()

foreach(menu ${menu_components})
  get_filename_component(component_name ${menu} NAME)
  set_source_files_properties(${menu} PROPERTIES QT_RESOURCE_ALIAS
                                                 ${component_name})
endforeach()

foreach(view ${view_components})
  get_filename_component(component_name ${view} NAME)
  set_source_files_properties(${view} PROPERTIES QT_RESOURCE_ALIAS
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
  buttons/CustomButton.qml
  buttons/CustomButtonBackground.qml
  buttons/CustomButtonContent.qml
  images/RoundedImage.qml
  draggers/WindowDragger.qml
  menus/MenuTab.qml
  menus/MenuTabs.qml
  views/DialogFrameView.qml
  RESOURCES
  "resources/media/music-note.png")
