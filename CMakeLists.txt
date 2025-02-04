cmake_minimum_required(VERSION 3.16)

project(Totodoro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core5Compat)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(config)

# Add the qmlmodules subdirectory
add_subdirectory(qmlmodules)

qt_add_executable(appTotodoro
    main.cpp
    ${CONFIG_CONST_VAL_SOURCES}
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

target_link_libraries(appTotodoro
    PRIVATE
        Qt6::Quick
        common_moduleplugin
)

include(GNUInstallDirs)
install(TARGETS appTotodoro
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
