cmake_minimum_required(VERSION 3.5)

project(SxUploadCore LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -g -O0")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC -std=c11 -g -O0")

include_directories(include/)
include_directories(liblog/include)
include_directories(binder/include)

add_compile_definitions(__ANDROID__)

# liblog
file(GLOB_RECURSE SRC_LIBLOG liblog/*.h liblog/*.c liblog/*.cpp)
add_library(log
    ${SRC_LIBLOG}
    )

# libbinder
file(GLOB_RECURSE SRC_BINDER binder/*.h binder/*.c binder/*.cpp)
add_library(binder
    ${SRC_BINDER}
    )
target_link_libraries(binder PUBLIC pthread)

# servicemanager
file(GLOB_RECURSE SRC_SM servicemanager/*.h
    servicemanager/*.c
    servicemanager/*.cpp)
add_library(servicemanager
    ${SRC_SM}
    )

