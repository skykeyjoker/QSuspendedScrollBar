cmake_minimum_required(VERSION 3.21)
project(QSuspendedScrollBar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets Core)

include_directories(../Src)

qt5_add_resources(qrc_FILES ../Src/res.qrc)

add_executable(QSuspendedScrollBar
        ${qrc_FILES}
        main.cpp
        ../Src/QSuspendedScrollBar.h
        ../Src/QSuspendedScrollBar.cpp
        QSuspendedScrollBar_ListWidget.h
        QSuspendedScrollBar_ListWidget.cpp
        QExampleWidget.h
        QExampleWidget.cpp
        QSuspendedScrollBar_Area.cpp
        QSuspendedScrollBar_Area.h)

target_link_libraries(QSuspendedScrollBar Qt5::Widgets Qt5::Core)