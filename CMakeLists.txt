cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fext-numeric-literals -Bstatic -pthread -static-libgcc -lsfml-system -lsfml-window")

set(SOURCE_FILES src/core/main.cpp
                 src/core/network/Generation.cpp src/core/network/Generation.h
                 src/core/network/Species.cpp src/core/network/Species.h
                 src/core/network/Genome.cpp src/core/network/Genome.h
                 src/core/network/Gene.cpp src/core/network/Gene.h
                 src/core/network/Neuron.h src/core/network/Neuron.cpp
                 src/core/simulation/Simulation.cpp src/core/simulation/Simulation.h
                 src/core/simulation/Player.cpp src/core/simulation/Player.h src/core/tui/Console.cpp
                 src/core/tui/Console.h src/core/tui/AnsiTextCode.h src/core/util/toStr.h src/core/util/Vector2.h
                 src/core/util/Delta.h src/core/simulation/Controller.cpp src/core/simulation/Controller.h
                 src/core/network/Network.cpp src/core/network/Network.h src/core/tui/TUI.cpp src/core/tui/TUI.h
                 src/core/util/Rect.h)


find_package(Threads REQUIRED)

add_executable(JamaisVu ${SOURCE_FILES} src/core/util/randomUtil.h src/core/util/randomUtil.h src/core/util/randomUtil.h)

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED window system graphics audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(JamaisVu ${SFML_LIBRARIES})