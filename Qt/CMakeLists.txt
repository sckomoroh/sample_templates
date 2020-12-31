cmake_minimum_required(VERSION 3.1.0)

project(Mp3Player VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Quick REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)

add_executable(Mp3Player
    src/main.cpp
    
    res/qml.qrc
)

target_link_libraries(
    Mp3Player 
    
    Qt5::Core 
    Qt5::Quick 
    Qt5::Multimedia
)
