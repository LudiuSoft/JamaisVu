cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES src/core/main.cpp src/core/network/Neuron.cpp src/core/network/Neuron.h)
add_executable(JamaisVu ${SOURCE_FILES} src/core/network/Gene.cpp src/core/network/Gene.h src/core/network/Genome.cpp src/core/network/Genome.h src/core/network/Species.cpp src/core/network/Species.h src/core/network/Generation.cpp src/core/network/Generation.h)

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add -I${wxWidgets_INCLUDE_DIRS}  -DWXUSINGDLL -D__WXGTK__ to CMAKE_CXX_CFLAGS when using wxWidgets