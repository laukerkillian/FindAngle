cmake_minimum_required(VERSION "3.5")
project("Test" VERSION "1.0" LANGUAGES CXX)

#set(CMAKE_CXX_COMPILER "C:/Qt/Tools/mingw810_64/bin/g++") #define compiler C++

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${QT_USE_FILE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        SvgLoader.cpp
        SvgLoader.h
        Triangle.cpp
        Triangle.hpp
        )


find_package(Qt5 REQUIRED COMPONENTS Widgets Svg)

add_executable(
        ${PROJECT_NAME}
        ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Svg)
