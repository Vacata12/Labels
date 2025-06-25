cmake_minimum_required(VERSION 3.14)
project(Labels)

# Set the C++ standard and debug flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -gdwarf-4")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add library source and header files
file(GLOB_RECURSE LIB_HEADERS Headers/*.h)
file(GLOB_RECURSE LIB_SOURCES src/*.cpp)

add_library(samplelib ${LIB_HEADERS} ${LIB_SOURCES})
target_include_directories(samplelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

# Fetch Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.1.1
)
FetchContent_MakeAvailable(Catch2)

# Add unit test executable
add_executable(unit-tests test/tests.cpp)
target_link_libraries(unit-tests PRIVATE samplelib Catch2::Catch2WithMain)
target_include_directories(unit-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

# Enable testing and Catch2 test discovery
include(CTest)
include(Catch)
catch_discover_tests(unit-tests)