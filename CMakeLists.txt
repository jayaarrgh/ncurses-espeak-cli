cmake_minimum_required(VERSION 3.5)

project(ncurses-espeak-cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(ncurses-espeak-cli ${SRC_FILES})

target_include_directories(ncurses-espeak-cli
  PRIVATE "${PROJECT_BINARY_DIR}/src")

target_link_libraries(ncurses-espeak-cli ncurses)
target_link_libraries(ncurses-espeak-cli espeak-ng)
