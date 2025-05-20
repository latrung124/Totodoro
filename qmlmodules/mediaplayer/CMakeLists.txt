qt_add_library(mediaplayer_module STATIC)

target_link_libraries(mediaplayer_module PRIVATE Qt6::Core5Compat)

qt_add_qml_module(
  mediaplayer_module
  URI
  MediaPlayerModule
  OUTPUT_DIRECTORY
  ${QT_QML_OUTPUT_DIRECTORY}/MediaPlayerModule
  VERSION
  1.0
  QML_FILES
  MediaPlayer.qml
  MediaButton.qml
  MediaEnumeration.qml
  RESOURCES
  "resources/next-button.png"
  "resources/play-button.png"
  "resources/pause-button.png"
  "resources/previous-button.png"
  "resources/repeat-button.png"
  "resources/shuffle-button.png"
  "resources/sound-button.png"
  "resources/default-media-artwork.png")
