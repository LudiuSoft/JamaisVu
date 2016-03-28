cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES src/core/main.cpp)
add_executable(JamaisVu ${SOURCE_FILES} src/core/network/generation/species/genome/Genome.cpp src/core/network/generation/species/genome/Genome.h src/core/network/generation/species/Species.cpp src/core/network/generation/species/Species.h src/core/network/generation/Generation.cpp src/core/network/generation/Generation.h)

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add -I${wxWidgets_INCLUDE_DIRS}  -DWXUSINGDLL -D__WXGTK__ to CMAKE_CXX_CFLAGS when using wxWidgets