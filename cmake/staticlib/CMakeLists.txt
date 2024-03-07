cmake_minimum_required(VERSION 3.16.3)
project(sharedlib_test)
set(CMAKE_BUILD_TYPE Release)

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_library(testStudent STATIC ${SOURCES})

install(TARGETS testStudent DESTINATION "/usr/lib")
