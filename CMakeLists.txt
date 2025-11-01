cmake_minimum_required(VERSION 3.16)

project(
  Totodoro
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Quick Core5Compat)
qt_standard_project_setup(REQUIRES 6.5)

set(CMAKE_INSTALL_PREFIX
    "${CMAKE_BINARY_DIR}/out"
    CACHE PATH "Installation Directory" FORCE)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH
    ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model" FORCE)

# Add the qmlmodules subdirectory
add_subdirectory(qmlmodules)

# add services subdirectory
add_subdirectory(services)

# add gateway subdirectory
add_subdirectory(gateway)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/out")

# set the config and const val sources
set(CONFIG_CONST_VAL_SOURCES
    ${CMAKE_SOURCE_DIR}/config/const_val/ApplicationConst.h)

# set the view-models
set(VM_SOURCES
    view-models/home/HomeViewModel.h
    view-models/pomodoro/PomodoroViewModel.h
    view-models/pomodoro/PomodoroTitleViewModel.h
    view-models/userprofile/UserProfileViewModel.h
    view-models/userprofile/UserSettingsViewModel.h
    view-models/taskmanagement/TaskGroupsViewModel.h
    view-models/taskmanagement/TaskGroupViewModel.h
    view-models/taskmanagement/TasksViewModel.h
    view-models/taskmanagement/TaskViewModel.h
    view-models/mediaplayer/MediaPlaybackViewModel.h
    view-models/mediaplayer/MediaPlayerViewModel.h
    view-models/home/HomeViewModel.cpp
    view-models/pomodoro/PomodoroViewModel.cpp
    view-models/pomodoro/PomodoroTitleViewModel.cpp
    view-models/userprofile/UserProfileViewModel.cpp
    view-models/userprofile/UserSettingsViewModel.cpp
    view-models/taskmanagement/TaskGroupsViewModel.cpp
    view-models/taskmanagement/TaskGroupViewModel.cpp
    view-models/taskmanagement/TasksViewModel.cpp
    view-models/taskmanagement/TaskViewModel.cpp
    view-models/mediaplayer/MediaPlayerViewModel.cpp
    view-models/mediaplayer/MediaPlaybackViewModel.cpp)

# set the models
set(MEDIAPLAYER_MODELS_SOURCES
    models/Model.h
    models/DatabaseModel.h
    models/SystemDataModel.h
    models/mediaplayer/MediaPlayerModel.h
    models/mediaplayer/MediaPlaybackModel.h
    models/userprofile/UserInformationModel.h
    models/userprofile/UserSettingsModel.h
    models/session/PomodoroModel.h
    models/taskmanagement/TaskModel.h
    models/taskmanagement/TaskGroupModel.h
    models/DatabaseModel.cpp
    models/SystemDataModel.cpp
    models/mediaplayer/MediaPlayerModel.cpp
    models/mediaplayer/MediaPlaybackModel.cpp
    models/userprofile/UserInformationModel.cpp
    models/userprofile/UserSettingsModel.cpp
    models/session/PomodoroModel.cpp
    models/taskmanagement/TaskModel.cpp
    models/taskmanagement/TaskGroupModel.cpp)

# set core sources
set(CONTROLLER_SOURCES
    core/controllers/ModelController.cpp
    core/controllers/ViewModelController.cpp core/controllers/ModelController.h
    core/controllers/ViewModelController.h)

set(UTIL_SOURCES
    utils/ThreadGuard.h utils/ScopedThread.h utils/qmltypes/PriorityTypeClass.h
    utils/qmltypes/MainTabTypeClass.h utils/qmltypes/DynamicObjectStateClass.h
    utils/qmltypes/PomodoroStateClass.h)

set(CORE_SOURCES
    core/services/ServiceConcreteHelper.h
    core/services/ServiceManager.h
    core/GuiApplication.h
    core/services/listeners/WMediaServiceListener.h
    core/services/listeners/ApiGatewayServiceListener.h
    core/services/consumer/ServiceConsumer.h
    core/services/consumer/ServiceMessageConsumer.h
    core/services/producer/ServiceProducer.h
    core/services/producer/ServiceMessageProducer.h
    core/services/producer/ServiceMessageCreator.h
    core/services/producer/window-service/WMediaInfoMessageCreator.h
    core/services/producer/window-service/WPlaybackControlsMessageCreator.h
    core/services/producer/window-service/WPlaybackInfoMessageCreator.h
    core/services/producer/window-service/WTimelinePropertiesMessageCreator.h
    core/services/producer/window-service/WPlayAsyncMessageCreator.h
    core/services/producer/window-service/WPauseAsyncMessageCreator.h
    core/services/producer/window-service/WPreviousAsyncMessageCreator.h
    core/services/producer/window-service/WNextAsyncMessageCreator.h
    core/services/producer/apigateway-service/UserInformationMessageCreator.h
    core/services/producer/apigateway-service/UserSettingsMessageCreator.h
    core/services/producer/apigateway-service/TaskMessageCreator.h
    core/services/producer/apigateway-service/TaskGroupMessageCreator.h
    core/services/queue/MessageQueue.h
    core/GuiApplication.cpp
    core/services/consumer/ServiceMessageConsumer.cpp
    core/services/producer/ServiceMessageProducer.cpp
    core/services/producer/window-service/WMediaInfoMessageCreator.cpp
    core/services/producer/window-service/WPlaybackControlsMessageCreator.cpp
    core/services/producer/window-service/WPlaybackInfoMessageCreator.cpp
    core/services/producer/window-service/WTimelinePropertiesMessageCreator.cpp
    core/services/producer/window-service/WPlayAsyncMessageCreator.cpp
    core/services/producer/window-service/WPauseAsyncMessageCreator.cpp
    core/services/producer/window-service/WPreviousAsyncMessageCreator.cpp
    core/services/producer/window-service/WNextAsyncMessageCreator.cpp
    core/services/producer/apigateway-service/UserInformationMessageCreator.cpp
    core/services/producer/apigateway-service/UserSettingsMessageCreator.cpp
    core/services/producer/apigateway-service/TaskMessageCreator.cpp
    core/services/producer/apigateway-service/TaskGroupMessageCreator.cpp
    core/services/listeners/WMediaServiceListener.cpp
    core/services/listeners/ApiGatewayServiceListener.cpp
    core/services/queue/MessageQueue.cpp
    core/services/ServiceManager.cpp)

set(CORE_FACTORY_SOURCES
    core/factories/ParamContainer.h
    core/factories/ViewModelFactory.h
    core/factories/view-model-producers/ViewModelProducer.h
    core/factories/view-model-producers/HomeVMProducer.h
    core/factories/view-model-producers/MediaPlayerVMProducer.h
    core/factories/view-model-producers/UserProfileVMProducer.h
    core/factories/view-model-producers/UserSettingsVMProducer.h
    core/factories/view-model-producers/HomeVMProducer.cpp
    core/factories/view-model-producers/MediaPlayerVMProducer.cpp
    core/factories/view-model-producers/UserProfileVMProducer.cpp
    core/factories/view-model-producers/UserSettingsVMProducer.cpp)

set(CORE_SERVICE_STRATEGIES
    core/services/strategies/IStrategy.h
    core/services/strategies/window-service/WMediaInfoExtractStrategy.h
    core/services/strategies/window-service/WPlaybackControlsExtractStrategy.h
    core/services/strategies/window-service/WPlaybackInfoExtractStrategy.h
    core/services/strategies/window-service/WTimelinePropertiesExtractStrategy.h
    core/services/strategies/window-service/WPlayAsyncExtractStrategy.h
    core/services/strategies/window-service/WPauseAsyncExtractStrategy.h
    core/services/strategies/window-service/WPreviousAsyncExtractStrategy.h
    core/services/strategies/window-service/WNextAsyncExtractStrategy.h
    core/services/strategies/apigateway-service/UserInformationExtractStrategy.h
    core/services/strategies/apigateway-service/UserSettingsExtractStrategy.h
    core/services/strategies/apigateway-service/PomodoroExtractStrategy.h
    core/services/strategies/apigateway-service/TaskExtractStrategy.h
    core/services/strategies/apigateway-service/TaskGroupExtractStrategy.h
    core/services/strategies/window-service/WMediaInfoExtractStrategy.cpp
    core/services/strategies/window-service/WPlaybackControlsExtractStrategy.cpp
    core/services/strategies/window-service/WPlaybackInfoExtractStrategy.cpp
    core/services/strategies/window-service/WTimelinePropertiesExtractStrategy.cpp
    core/services/strategies/window-service/WPlayAsyncExtractStrategy.cpp
    core/services/strategies/window-service/WPauseAsyncExtractStrategy.cpp
    core/services/strategies/window-service/WPreviousAsyncExtractStrategy.cpp
    core/services/strategies/window-service/WNextAsyncExtractStrategy.cpp
    core/services/strategies/apigateway-service/UserInformationExtractStrategy.cpp
    core/services/strategies/apigateway-service/UserSettingsExtractStrategy.cpp
    core/services/strategies/apigateway-service/PomodoroExtractStrategy.cpp
    core/services/strategies/apigateway-service/TaskExtractStrategy.cpp
    core/services/strategies/apigateway-service/TaskGroupExtractStrategy.cpp)

set(CORE_SERVICE_MSG_SOURCES
    core/services/messages/Message.h
    core/services/messages/MessageId.h
    core/services/messages/window-service/WMediaInfoMessage.h
    core/services/messages/window-service/WPlaybackControlsMessage.h
    core/services/messages/window-service/WPlaybackInfoMessage.h
    core/services/messages/window-service/WTimelinePropertiesMessage.h
    core/services/messages/window-service/WPlayAsyncMessage.h
    core/services/messages/window-service/WPauseAsyncMessage.h
    core/services/messages/window-service/WPreviousAsyncMessage.h
    core/services/messages/window-service/WNextAsyncMessage.h
    core/services/messages/apigateway-service/UserInformationMessage.h
    core/services/messages/apigateway-service/UserSettingsMessage.h
    core/services/messages/apigateway-service/PomodoroMessage.h
    core/services/messages/apigateway-service/TaskMessage.h
    core/services/messages/apigateway-service/TaskGroupMessage.h
    core/services/messages/window-service/WMediaInfoMessage.cpp
    core/services/messages/window-service/WPlaybackControlsMessage.cpp
    core/services/messages/window-service/WPlaybackInfoMessage.cpp
    core/services/messages/window-service/WTimelinePropertiesMessage.cpp
    core/services/messages/window-service/WPlayAsyncMessage.cpp
    core/services/messages/window-service/WPauseAsyncMessage.cpp
    core/services/messages/window-service/WPreviousAsyncMessage.cpp
    core/services/messages/window-service/WNextAsyncMessage.cpp
    core/services/messages/apigateway-service/UserInformationMessage.cpp
    core/services/messages/apigateway-service/UserSettingsMessage.cpp
    core/services/messages/apigateway-service/PomodoroMessage.cpp
    core/services/messages/apigateway-service/TaskMessage.cpp
    core/services/messages/apigateway-service/TaskGroupMessage.cpp)

set(HELPER_SOURCES helpers/ParamContainerHelper.h)

qt_add_executable(
  appTotodoro
  main.cpp
  ${INTERFACES_SOURCES} # this should be removed and installed to the include
                        # directory
  ${CONFIG_CONST_VAL_SOURCES}
  ${VM_SOURCES}
  ${MEDIAPLAYER_MODELS_SOURCES}
  ${CONTROLLER_SOURCES}
  ${CORE_SOURCES}
  ${CORE_SERVICE_MSG_SOURCES}
  ${CORE_SERVICE_STRATEGIES}
  ${CORE_FACTORY_SOURCES}
  ${HELPER_SOURCES}
  ${UTIL_SOURCES})

qt_add_qml_module(
  appTotodoro
  URI
  Totodoro
  VERSION
  1.0
  RESOURCE_PREFIX
  /resources/qml
  IMPORT_PATH
  ${QML_IMPORT_PATH}/MediaPlayerModule
  ${QML_IMPORT_PATH}/CommonModule
  ${QML_IMPORT_PATH}/WindowModule
  ${QML_IMPORT_PATH}/PomodoroModule
  ${QML_IMPORT_PATH}/TasksListModule
  ${QML_IMPORT_PATH}/TaskGroupListModule
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
  "resources/icon/White/512x512.png")

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
set_target_properties(
  appTotodoro
  PROPERTIES # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTotodoro
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

target_include_directories(appTotodoro PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(QML_PLUGINS
    common_moduleplugin
    mediaplayer_moduleplugin
    window_moduleplugin
    tasks_list_moduleplugin
    task_group_list_moduleplugin
    pomodoro_moduleplugin
    userprofile_moduleplugin)

set(SERVICE_LIBRARIES WMediaService ApiGatewayService ServiceFactory)

target_link_libraries(appTotodoro PRIVATE Qt6::Quick ${QML_PLUGINS}
                                          ${SERVICE_LIBRARIES})

include(GNUInstallDirs)
install(
  TARGETS appTotodoro
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
