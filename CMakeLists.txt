cmake_minimum_required(VERSION 3.16)

project(Totodoro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core5Compat)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(config)

# Add the qmlmodules subdirectory
add_subdirectory(qmlmodules)

# set the view-models
set(MEDIAPLAYER_VM_SOURCES
    view-models/mediaplayer/MediaPlayerViewModel.cpp
    view-models/mediaplayer/MediaPlaybackViewModel.cpp

    view-models/mediaplayer/MediaPlayerViewModel.h
    view-models/mediaplayer/MediaPlaybackViewModel.h
)

# set the models
set(MEDIAPLAYER_MODELS_SOURCES
    models/mediaplayer/MediaPlayerModel.cpp
    models/mediaplayer/MediaPlaybackModel.cpp

    models/mediaplayer/MediaPlayerModel.h
    models/mediaplayer/MediaPlaybackModel.h
)

# set core sources
set(CONTROLLER_SOURCES
    core/controllers/ModelController.cpp
    core/controllers/ViewModelController.cpp

    core/controllers/ModelController.h
    core/controllers/ViewModelController.h
)

set(CONNECTION_SOURCES
    core/connections/ConnectionManager.cpp

    core/connections/ConnectionManager.h
)

qt_add_executable(appTotodoro
    main.cpp
    ${CONFIG_CONST_VAL_SOURCES}
    ${MEDIAPLAYER_VM_SOURCES}
    ${MEDIAPLAYER_MODELS_SOURCES}
    ${CONTROLLER_SOURCES}
    ${CONNECTION_SOURCES}
)

qt_add_qml_module(appTotodoro
    URI Totodoro
    VERSION 1.0
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTotodoro PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTotodoro
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appTotodoro
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(appTotodoro
    PRIVATE
        Qt6::Quick
        common_moduleplugin
        mediaplayer_moduleplugin
)

include(GNUInstallDirs)
install(TARGETS appTotodoro
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
