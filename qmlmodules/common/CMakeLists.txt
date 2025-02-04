qt_add_library(common_module STATIC)

target_link_libraries(common_module
    PRIVATE
        Qt6::Core5Compat
)

set(button_components
    buttons/CustomButton.qml
    buttons/CustomButtonBackground.qml
    buttons/CustomButtonContent.qml
)

foreach(button ${button_components})
    get_filename_component(component_name ${button} NAME)
    set_source_files_properties(${button} PROPERTIES QT_RESOURCE_ALIAS ${component_name})
endforeach()

qt_add_qml_module(common_module
    URI CommonModule
    VERSION 1.0
    QML_FILES
        WindowControl.qml
        buttons/CustomButton.qml
        buttons/CustomButtonBackground.qml
        buttons/CustomButtonContent.qml
    RESOURCES
        "resources/window/close-button.png"
        "resources/window/maximize-button.png"
        "resources/window/minimize-button.png"
)
