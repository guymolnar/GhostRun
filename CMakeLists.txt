cmake_minimum_required(VERSION 3.20)
project(GhostRun)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

# Shared sources
set(SHARED_SOURCES
        src/shared/aes.cpp
        src/shared/steg.cpp
)

set(SHARED_INCLUDES
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src/external)

# Builder executable
add_executable(GhostRun-Builder
        src/builder/main.cpp
        ${SHARED_SOURCES}
        src/shared/steg.cpp)

target_include_directories(GhostRun-Builder PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRun-Builder PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Runner executable
add_executable(GhostRun-Runner
        src/runner/main.cpp
        ${SHARED_SOURCES}
        src/shared/steg.cpp)

target_include_directories(GhostRun-Runner PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRun-Runner PRIVATE OpenSSL::SSL OpenSSL::Crypto)