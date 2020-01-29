cmake_minimum_required(VERSION 3.5)

project(Hit-The-Bucket) # VERSION 1.0 LANGUAGES CXX

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Hit-The-Bucket main.cpp)

target_link_libraries(Hit-The-Bucket sfml-graphics sfml-window)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
