cmake_minimum_required(VERSION 3.16)
project(task05 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

find_package (Threads)

set(SOURCE_FILES
        Thread.h
        Student.h
        Teacher.h

        Thread.cpp
        Student.cpp
        Teacher.cpp
        main.cpp
        )

add_executable(task05 ${SOURCE_FILES})

target_link_libraries (task05 ${CMAKE_THREAD_LIBS_INIT})
