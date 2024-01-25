cmake_minimum_required(VERSION 3.16)

project(AAN-Z-APP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appAAN-Z-APP
    main.cpp
    QML.qrc
)

qt_add_qml_module(appAAN-Z-APP
    URI AAN-Z-APP
    VERSION 1.0
    QML_FILES main.qml
    #QML_FILES UI/Num_Systems/Num_Systems.qml
    #qml/Num_Systems/Num_Systems.qml
    #RESOURCES assets.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAAN-Z-APP PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAAN-Z-APP
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAAN-Z-APP
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appAAN-Z-APP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
