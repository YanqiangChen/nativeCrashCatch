cmake_minimum_required(VERSION 3.10.2)
include_directories(breakpad/src breakpad/src/common/android/include)

project("nativecrash")
add_library(
        nativecrash
        SHARED
        nativecrash.cpp)
target_link_libraries( # Specifies the target library.
        nativecrash breakpad
        log)
add_subdirectory(breakpad)