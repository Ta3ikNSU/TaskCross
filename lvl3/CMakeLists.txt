cmake_minimum_required(VERSION 3.21)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/ta3ik/Qt/6.2.2/macos/lib/cmake/")

include_directories("/Users/ta3ik/CLionProjects/untitled2")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled2 main.cpp Figure.h VectorDocument.h)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

