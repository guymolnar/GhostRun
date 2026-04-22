cmake_minimum_required(VERSION 3.20)
project(GhostRun)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

set(SHARED_SOURCES
        src/aes/aes.cpp
        src/steg/steg.cpp
        src/utils/utils.cpp
        src/loader/loader.cpp
        include/payload/payload.hpp
        src/payload/payload.cpp
)

set(SHARED_INCLUDES
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/external
)

# Builder executable
add_executable(GhostRunBuilder
        src/builder/main.cpp
        ${SHARED_SOURCES}
        include/payload/payload.hpp
        src/payload/payload.cpp
)
target_include_directories(GhostRunBuilder PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRunBuilder PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Runner executable
add_executable(GhostRunRunner
        src/runner/main.cpp
        ${SHARED_SOURCES}
        include/payload/payload.hpp
        src/payload/payload.cpp
)
target_include_directories(GhostRunRunner PRIVATE ${SHARED_INCLUDES})
target_link_libraries(GhostRunRunner PRIVATE OpenSSL::SSL OpenSSL::Crypto)
