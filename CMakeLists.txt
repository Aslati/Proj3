cmake_minimum_required(VERSION 3.15...3.27)

project(PROJ3)

find_package(Python COMPONENTS Interpreter Development)
set(pybind11_DIR "C:/Python312/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/audio)

add_subdirectory(matplotplusplus)


Python_add_library(_PROJ3 src/PROJ3/main.cpp)
    target_link_libraries(_PROJ3 PRIVATE pybind11::headers)
    set_target_properties(_PROJ3 PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION ON
        CXX_VISIBILITY_PRESET ON
        VISIBILITY_INLINES_HIDDEN ON
    )
target_compile_definitions(_PROJ3 PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS _PROJ3 LIBRARY DESTINATION src/PROJ3)