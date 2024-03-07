Sample cmake project - creates a static library
  CMakeLists.txt lists the static library name, the inc and src directories

How to build the project:
  1. Create a build directory at the project root (cmake/staticlib)
  2. cd build
  3. Run the command 'cmake ..'
  4. Cmake creates CMakeFiles, CMakeCache.txt, Makefile, cmake_install.cmake in the build directory itself
  5. Run the command 'make'
  6. Static library libtestStudent.a is created in the build directory
