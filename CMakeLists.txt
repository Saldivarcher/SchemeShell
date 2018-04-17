cmake_minimum_required(VERSION 3.0)
project(scheme)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG}")

file(GLOB_RECURSE sources src/*.cpp)

add_executable(scheme ${sources})

target_include_directories(scheme PUBLIC include/)
install(TARGETS scheme DESTINATION example_destination)

set(CPACK_PACKAGE_NAME "Scheme")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)
