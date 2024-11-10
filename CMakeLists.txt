cmake_minimum_required(VERSION 3.29)
project(cheat_dl)

set(CMAKE_CXX_STANDARD 20)

find_package(imgui REQUIRED)
find_package(glm REQUIRED)

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
        imgui/backends/imgui_impl_dx9.h
        imgui/backends/imgui_impl_dx9.cpp
        gui/gui.cpp
        gui/gui.h
        matrix3x4.h
        type.h
        externallib/externallib.h
        externallib/signature.h
        externallib/signature.cpp
        externallib/memory.h
        externallib/memory.cpp
        settings.h
        global_t.h
        settings.cpp
        dl_memory.h
        dl_memory.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        imgui::imgui
        d3d9
        d3d11
        libMinHook-x64-v141-mtd.lib
        d3dcompiler
        dxgi
        Shell32
        winmm.lib
        glm::glm)
target_include_directories(${PROJECT_NAME} PRIVATE .)
