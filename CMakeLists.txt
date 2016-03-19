cmake_minimum_required(VERSION 3.2)
project(JamaisVu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I${wxWidgets_INCLUDE_DIRS}  -DWXUSINGDLL -D__WXGTK__")

set(SOURCE_FILES src/core/main.cpp)
add_executable(JamaisVu ${SOURCE_FILES})

#LIBS

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

##wxWidgets
find_package(wxWidgets 3.0 REQUIRED)
if(wxWidgets_FOUND)
    include_directories(${wxWidgets_INCLUDE_DIRS})
    target_link_libraries(JamaisVu ${wxWidgets_LIBRARIES})
endif()
