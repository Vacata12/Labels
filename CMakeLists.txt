cmake_minimum_required(VERSION 3.14)
project(Labels)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the samplelib library
add_library(samplelib
    Headers/Labels.h
    Headers/TextTransformation.h
    Headers/SimpleLabel.h
    src/SimpleLabel.cpp
    Headers/RichLabel.h
    src/RichLabel.cpp
    Headers/Capitalize.h
    src/Capitalize.cpp
    Headers/LeftTrim.h
    src/LeftTrim.cpp
    Headers/RightTrim.h
    src/RightTrim.cpp
    Headers/NormalizeSpace.h
    src/NormalizeSpace.cpp
    Headers/Decorate.h
    src/Decorate.cpp
    Headers/Censor.h
    src/Censor.cpp
    Headers/Replace.h
    src/Replace.cpp
)

# Specify the include directories for samplelib
target_include_directories(samplelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

# Make Catch2 available
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.1.1
)

FetchContent_MakeAvailable(Catch2)

# Executable target for the unit tests
add_executable(unit-tests
    test/tests.cpp
)

target_link_libraries(
    unit-tests
    PRIVATE
    samplelib
    Catch2::Catch2WithMain
)

target_include_directories(unit-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

# Automatically register all tests
include(CTest)
include(Catch)
catch_discover_tests(unit-tests)