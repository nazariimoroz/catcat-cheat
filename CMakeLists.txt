cmake_minimum_required(VERSION 3.29)
project(cheat_dl)

set(CMAKE_CXX_STANDARD 20)

find_package(imgui REQUIRED)

file(GLOB ${PROJECT_NAME}_SDK_SRC
        "source2sdk/*/*.h"
        "source2sdk/*/*.hpp"
        #"imgui/*/*.hpp"
        #"imgui/*/*.h"
        #"imgui/*/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp
        ${${PROJECT_NAME}_SDK_SRC}
        imgui/backends/imgui_impl_win32.h
        imgui/backends/imgui_impl_win32.cpp
        imgui/backends/imgui_impl_opengl3.h
        imgui/backends/imgui_impl_opengl3.cpp
        matrix3x4.h)

target_link_libraries(${PROJECT_NAME} PRIVATE
        imgui::imgui
        d3d11
        d3dcompiler
        dxgi)
target_include_directories(${PROJECT_NAME} PRIVATE .)
