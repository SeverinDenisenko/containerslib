cmake_minimum_required(VERSION 3.21)

project(containers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

option(ENABLE_TESTING OFF)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(containers INTERFACE)

target_include_directories(containers 
    INTERFACE 
        ${PROJECT_INCLUDE_DIR}
)

if (ENABLE_TESTING AND PROJECT_IS_TOP_LEVEL)
    enable_testing()
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/unittestlib)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
