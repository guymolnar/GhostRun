cmake_minimum_required(VERSION 4.1)
project(GhostRun)

set(CMAKE_CXX_STANDARD 20)

add_executable(GhostRun main.cpp
        src/external/stb_image.h
        src/external/stb_image_write.h)
