cmake_minimum_required(VERSION 3.20)
project(GhostRun)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

# Shared sources
set(SHARED_SOURCES
        src/shared/aes.cpp
        src/shared/steg.cpp
        src/shared/utils.cpp
        include/utils.hpp
        src/runner/loader.cpp
        include/loader.hpp
)

set(SHARED_INCLUDES
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src/external)

# Builder executable
add_executable(GhostRunBuilder
        src/builder/main.cpp
        ${SHARED_SOURCES}
        src/shared/steg.cpp
        src/shared/utils.cpp
        include/utils.hpp
        src/runner/loader.cpp
        include/loader.hpp)

target_include_directories(GhostRunBuilder PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRunBuilder PRIVATE OpenSSL::SSL OpenSSL::Crypto)


# Runner executable
add_executable(GhostRunRunner
        src/runner/main.cpp
        ${SHARED_SOURCES}
        src/shared/steg.cpp
        src/shared/utils.cpp
        include/utils.hpp
        src/runner/loader.cpp
        include/loader.hpp)

target_include_directories(GhostRunRunner PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRunRunner PRIVATE OpenSSL::SSL OpenSSL::Crypto)

