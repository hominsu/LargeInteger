cmake_minimum_required(VERSION 3.20)
project(LargeInteger
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


# ============================== select operating system  ==============================
message("")
message("Operation system is ${CMAKE_SYSTEM}")
message("Current compiler: ${CMAKE_CXX_COMPILER_ID}")
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    link_directories(/opt/homebrew/lib)
    include_directories(/opt/homebrew/include)
    message(STATUS "Load link directories from /opt/homebrew/lib")
    message(STATUS "Load include directories from /opt/homebrew/include")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    link_directories(/usr/local/lib)
    include_directories(/usr/local/include)
    message(STATUS "Load link directories from /usr/local/lib")
    message(STATUS "Load include directories from /usr/local/include")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    # setting vcpkg toolchain file
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
            CACHE STRING "Vcpkg toolchain file")

    if (MSVC)   # if msvc
        # because opencv is use libcmt, so don't use dll
        # use the static C/CXX library for all build types; if Debug, set MultiThreadedDebug(MTd), else, set MultiThreaded(MT)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        # setting charset
        add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
        add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    elseif (MINGW)  # if mingw
        # setting vcpkg
        if (DEFINED ENV{VCPKG_DEFAULT_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
            set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}" CACHE STRING "")
        endif ()
    endif ()
else ()
    message(FATAL_ERROR "Platform ${CMAKE_SYSTEM} is not support for this project")
endif ()


# ============================== set output dir ==============================

# debug, ARCHIVE means static lib, LIBRARY means dynamic lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

# release
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# ============================== add executable and link libraries ==============================
file(GLOB ProjectSRC
        "*.cc")

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-DDebug)
    message(STATUS "CMake Build Type: Debug")
    message("")
elseif (CMAKE_BUILD_TYPE STREQUAL Release)
    ADD_DEFINITIONS(-DRelease)
    message(STATUS "CMake Build Type: Release")
    message("")
endif ()

add_executable(${PROJECT_NAME} ${ProjectSRC})
