cmake_minimum_required(VERSION 3.16)

project(Totodoro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core5Compat)

qt_standard_project_setup(REQUIRES 6.5)

set(SERVICE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/service_install)

# Add the qmlmodules subdirectory
add_subdirectory(qmlmodules)

# add services subdirectory
add_subdirectory(services)

# set the config and const val sources
set (CONFIG_CONST_VAL_SOURCES
    ${CMAKE_SOURCE_DIR}/config/const_val/ApplicationConst.h
)

# set the view-models
set(MEDIAPLAYER_VM_SOURCES
    view-models/mediaplayer/MediaPlayerViewModel.cpp
    view-models/mediaplayer/MediaPlaybackViewModel.cpp

    view-models/mediaplayer/MediaPlayerViewModel.h
    view-models/mediaplayer/MediaPlaybackViewModel.h
)

# set the models
set(MEDIAPLAYER_MODELS_SOURCES
    models/Model.h
    models/DatabaseModel.h
    models/SystemDataModel.h
    models/mediaplayer/MediaPlayerModel.cpp
    models/mediaplayer/MediaPlaybackModel.cpp

    models/DatabaseModel.cpp
    models/SystemDataModel.cpp
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

set(UTIL_SOURCES
    utils/ThreadGuard.h
)

set(CORE_SOURCES
    core/GuiApplication.cpp
    core/services/service-consumer/ServiceMessageConsumer.cpp
    core/services/service-producer/ServiceMessageProducer.cpp
    core/services/service-listeners/WMediaServiceListener.cpp
    core/services/service-messages/window-service/WMediaInfoMessage.cpp
    core/services/service-messages/window-service/WPlaybackControlsMessage.cpp
    core/services/service-messages/window-service/WPlaybackInfoMessage.cpp
    core/services/service-queue/ServiceMessageQueue.cpp
    core/services/ServiceConcreteHelper.h
    core/services/ServiceManager.h
    core/services/service-handlers/ServiceMessageHandler.h
    core/services/service-handlers/WMediaInfoMessageHandler.h

    core/GuiApplication.h
    core/services/service-listeners/WMediaServiceListener.h
    core/services/service-consumer/ServiceConsumer.h
    core/services/service-consumer/ServiceMessageConsumer.h
    core/services/service-producer/ServiceProducer.h
    core/services/service-producer/ServiceMessageProducer.h
    core/services/service-messages/ServiceMessage.h
    core/services/service-messages/ServiceMessageId.h
    core/services/service-messages/window-service/WMediaInfoMessage.h
    core/services/service-messages/window-service/WPlaybackControlsMessage.h
    core/services/service-messages/window-service/WPlaybackInfoMessage.h
    core/services/service-queue/MessageQueue.h
    core/services/service-queue/ServiceMessageQueue.h
    core/services/ServiceManager.cpp
    core/services/service-handlers/WMediaInfoMessageHandler.cpp
)

qt_add_executable(appTotodoro
    main.cpp
    ${INTERFACES_SOURCES} # this should be removed and installed to the include directory
    ${CONFIG_CONST_VAL_SOURCES}
    ${MEDIAPLAYER_VM_SOURCES}
    ${MEDIAPLAYER_MODELS_SOURCES}
    ${CONTROLLER_SOURCES}
    ${CORE_SOURCES}
    ${UTIL_SOURCES}
)

qt_add_qml_module(appTotodoro
    URI Totodoro
    VERSION 1.0
    RESOURCE_PREFIX /resources/qml
    QML_FILES
        Main.qml
    RESOURCES
	    "resources/icon/Black/16x16.png"
        "resources/icon/Black/24x24.png"
        "resources/icon/Black/32x32.png"
        "resources/icon/Black/48x48.png"
        "resources/icon/Black/128x128.png"
        "resources/icon/Black/256x256.png"
        "resources/icon/Black/512x512.png"
        "resources/icon/White/16x16.png"
        "resources/icon/White/24x24.png"
        "resources/icon/White/32x32.png"
        "resources/icon/White/48x48.png"
        "resources/icon/White/128x128.png"
        "resources/icon/White/256x256.png"
        "resources/icon/White/512x512.png"
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
        wmedia_service
        service_factory
)

include(GNUInstallDirs)
install(TARGETS appTotodoro
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
