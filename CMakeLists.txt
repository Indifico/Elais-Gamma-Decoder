cmake_minimum_required(VERSION 3.10.0)
project(ElaisGammaDecoder VERSION 1.0 LANGUAGES C CXX)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

add_executable(egdecoder src/main.cpp)

install(TARGETS egdecoder DESTINATION bin)

