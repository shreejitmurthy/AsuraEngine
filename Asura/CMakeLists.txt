cmake_minimum_required(VERSION 3.28)
project(Asura VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_subdirectory(vendor/SDL)
add_subdirectory(vendor/spdlog)

include_directories(
    vendor/
    vendor/glad
    vendor/include/
)

find_package(OpenGL REQUIRED)

set(ASURA_LIBS
    OpenGL::GL
    SDL3::SDL3
    spdlog
)

set(ASURA_SRC
    src/main.cpp
)

set(DEP_SRC
    vendor/glad/glad.c
)

add_executable(Asura ${ASURA_SRC} ${DEP_SRC})

target_link_libraries(Asura ${ASURA_LIBS})
