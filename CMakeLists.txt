cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES src/core/main.cpp
                 src/core/network/Generation.cpp src/core/network/Generation.h
                 src/core/network/Species.cpp src/core/network/Species.h
                 src/core/network/Genome.cpp src/core/network/Genome.h
                 src/core/network/Gene.cpp src/core/network/Gene.h
                 src/core/network/Neuron.h src/core/network/Neuron.cpp
                 src/core/simulation/Simulation.cpp src/core/simulation/Simulation.h
                 src/core/simulation/Player.cpp src/core/simulation/Player.h src/core/cli/Console.cpp
                 src/core/cli/Console.h src/core/cli/AnsiTextOptions.h)

add_executable(JamaisVu ${SOURCE_FILES})

find_package(Threads REQUIRED)

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add -I${wxWidgets_INCLUDE_DIRS}  -DWXUSINGDLL -D__WXGTK__ to CMAKE_CXX_CFLAGS when using wxWidgets
