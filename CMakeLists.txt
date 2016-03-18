cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/core/main.cpp)
add_executable(JamaisVu ${SOURCE_FILES})

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(QT_QMAKE_EXECUTABLE D:/Qt/4.8.5/bin/qmake.exe)

##QT
find_package(Qt 4 REQUIRED)
if(QT_FOUND)
    include_directories(${QT_INCLUDES})
    target_link_libraries(JamaisVu ${QT_LIBRARIES})
endif()
