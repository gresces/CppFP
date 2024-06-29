#########################
# @file: CMakeLists.txt #
# @author: Gresces      #
# @date: 2024-6-28      #
#########################

# Use gcc-14 as default compiler
cmake_minimum_required (VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
project("CppFP")
set(PROJECT_NAME "CppFP")

# C Compiler settings
add_compile_options(-Werror -g)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)                             # Type : Debug
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)   # Bin Path : bin
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)      # Lib Path : lib
set(RESC_DIR ${PROJECT_SOURCE_DIR}/resource)
set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/examples)

# Compile and build
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB subdirectories CMAKE_USE_RELATIVE_PATHS "${EXAMPLE_DIR}/*" )
message("${subdirectories}")
foreach(subdir ${subdirectories})
    if(IS_DIRECTORY ${subdir})
        add_subdirectory(${subdir})
    endif(IS_DIRECTORY ${subdir})
endforeach(subdir ${subdirectories})
