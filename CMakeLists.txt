cmake_minimum_required(VERSION 3.28)

project(Chip8VM
	VERSION 1.0.0
	LANGUAGES CXX
)

# CONFIGS
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CHIP8VM_TARGET_NAME Chip8VM)

# Extensions
include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog"
        GIT_TAG "v1.14.1"
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        sdl2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL"
        GIT_TAG "release-2.30.6"
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(sdl2)

add_subdirectory(${CHIP8VM_TARGET_NAME})
