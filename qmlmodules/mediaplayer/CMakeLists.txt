qt_add_library(mediaplayer_module STATIC)

qt_add_qml_module(mediaplayer_module
    URI MediaPlayerModule
    VERSION 1.0
    QML_FILES
        MediaPlayer.qml
    RESOURCES
        "resources/next-button.png"
        "resources/play-button.png"
        "resources/previous-button.png"
        "resources/repeat-button.png"
        "resources/shuffle-button.png"
)
