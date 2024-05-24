# Require CMake 3.15+ (matching scikit-build-core) Use new versions of all
# policies up to CMake 3.27
cmake_minimum_required(VERSION 3.15...3.27)

# Scikit-build-core sets these values for you, or you can just hard-code the
# name and version.
project(PROJ3)

# Find the module development requirements (requires FindPython from 3.17 or
# scikit-build-core's built-in backport)
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

# Add a library using FindPython's tooling (pybind11 also provides a helper like
# this)
python_add_library(_PROJ3 MODULE src/main.cpp WITH_SOABI)
target_link_libraries(_PROJ3 PRIVATE pybind11::headers)

# This is passing in the version as a define just as an example
target_compile_definitions(_PROJ3 PRIVATE VERSION_INFO=${PROJECT_VERSION})

# The install directory is the output (wheel) directory
install(TARGETS _PROJ3 DESTINATION src/scikit_build_example)


add_subdirectory(matplotplusplus)
target_link_libraries(_PROJ3 PUBLIC matplot)

include_directories (${AudioFile_SOURCE_DIR})
add_definitions (-DPROJECT_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries (_PROJ3 PUBLIC AudioFile)