cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I${wxWidgets_INCLUDE_DIRS}  -DWXUSINGDLL -D__WXGTK__")

set(SOURCE_FILES src/core/main.cpp)
add_executable(JamaisVu ${SOURCE_FILES} src/core/network/generation/species/genome/genome.cpp src/core/network/generation/species/genome/genome.h src/core/network/generation/species/species.cpp src/core/network/generation/species/species.h src/core/network/generation/generation.cpp src/core/network/generation/generation.h)

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})