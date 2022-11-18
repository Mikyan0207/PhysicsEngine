cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(PhysicsEngine CXX)

include(CMakeDependentOption)

# Ability to toggle between the static and DLL versions of the MSVC runtime library
# Windows Store only supports the DLL version
cmake_dependent_option(USE_STATIC_MSVC_RUNTIME_LIBRARY "Use the static MSVC runtime library" ON "MSVC;NOT WINDOWS_STORE" OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Distribution")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release;ReleaseASAN;ReleaseUBSAN;ReleaseCoverage;Distribution")
endif()

# Fill in the path to the asan libraries
set(CLANG_LIB_PATH "\"$(VSInstallDir)\\VC\\Tools\\Llvm\\x64\\lib\\clang\\${CMAKE_CXX_COMPILER_VERSION}\\lib\\windows\"")
	
# 64 bit architecture
set(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE "x64")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set runtime library
if (USE_STATIC_MSVC_RUNTIME_LIBRARY)
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Set general compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /std:c17 /Wall /Zc:__cplusplus /Gm- /WX /MP /nologo /diagnostics:classic /FC /fp:except- /Zc:inline /Zi")

# Remove any existing compiler flag that enables RTTI
string(REPLACE "/GR" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

# Set compiler flag for disabling RTTI
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")

# Set compiler flags for various configurations
set(CMAKE_CXX_FLAGS_DEBUG "/GS /Od /Ob0 /RTC1")
set(CMAKE_CXX_FLAGS_RELEASE "/GS- /Gy /O2 /Oi /Ot")
set(CMAKE_CXX_FLAGS_DISTRIBUTION "/GS- /Gy /O2 /Oi /Ot")
set(CMAKE_CXX_FLAGS_RELEASEASAN "-fsanitize=address /Od")
set(CMAKE_CXX_FLAGS_RELEASEUBSAN "-fsanitize=undefined,implicit-conversion,float-divide-by-zero,local-bounds -fno-sanitize-recover=all")
set(CMAKE_CXX_FLAGS_RELEASECOVERAGE "-fprofile-instr-generate -fcoverage-mapping")

set(REPOSITORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)

include(${REPOSITORY_ROOT}/PhysicsEngine/Engine.cmake)
