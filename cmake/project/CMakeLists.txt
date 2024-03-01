cmake_minimum_required(VERSION 3.16.3)
project(project_test)

include_directories(inc)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/Student.cpp)

#Or
#file(GLOB SOURCES "src/*.cpp")

add_executable(project)
add_subdirectory(src)
