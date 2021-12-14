cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(task01 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(SOURCE_FILES
    ProgrammingLanguage.h
    Random.h
    Container.h
    Functional.h
    Procedural.h
    ObjectOriented.h

    ProgrammingLanguage.cpp
    Container.cpp
    Functional.cpp
    Procedural.cpp
    ObjectOriented.cpp
    main.cpp
)

add_executable(task01 ${SOURCE_FILES})
