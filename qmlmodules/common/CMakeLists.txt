qt_add_library(common_module STATIC)

qt_add_qml_module(common_module
    URI CommonModule
    VERSION 1.0
    QML_FILES
        WindowControl.qml
    
    RESOURCES
        "resources/window/close-button.png"
        "resources/window/maximize-button.png"
        "resources/window/minimize-button.png"
)