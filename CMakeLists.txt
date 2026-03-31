cmake_minimum_required(VERSION 3.20)
project(GhostRun)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

add_executable(GhostRun
        src/external/stb_image.h
        src/external/stb_image_write.h
        src/shared/aes.hpp
        src/shared/aes.cpp
)

target_link_libraries(GhostRun PRIVATE OpenSSL::SSL OpenSSL::Crypto)