Sample cmake project - creates a shared library
  CMakeLists.txt lists the shared library name, the inc and src directories

How to build the project:
  1. Create a build directory at the project root (cmake/sharedlib)
  2. cd build
  3. Run the command 'cmake ..'
  4. Cmake creates CMakeFiles, CMakeCache.txt, Makefile, cmake_install.cmake in the build directory itself
  5. Run the command 'make'
  6. Shared library libtestStudent.so is created in the build directory
