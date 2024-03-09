cmake_minimum_required(VERSION 3.16.3)
project(testLibrary)

#For shared library
#set(LIBS libtestStudent.so)
#link_directories(../sharedlib/build)
#include_directories(../sharedlib/inc)

#For static library
set(LIBS libtestStudent.a)
link_directories(../staticlib/build)
include_directories(../staticlib/inc)

add_executable(testlib main.cpp)
target_link_libraries(testlib ${LIBS})
