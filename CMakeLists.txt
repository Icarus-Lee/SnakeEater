cmake_minimum_required(VERSION 3.15)

project(
  SnakeEater
  VERSION 1.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
    src/main.cc
    src/controller/GameController.cc
    src/model/Snake.cc
    src/model/Food.cc
    src/model/Map.cc
    src/view/TUIRenderer.cc
)

add_executable(SnakeEater ${SOURCE_FILES})

target_include_directories(SnakeEater PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MSVC)
  target_compile_options(SnakeEater PRIVATE /W4 /WX)
else()
  target_compile_options(SnakeEater PRIVATE -Wall -Wextra -pedantic -Werror)
endif()