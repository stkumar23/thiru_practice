Sample cmake project to use either a static or shared library
  CMakeLists.txt lists the static or shared library name, path, inc path

How to build the project:
  1. Download either the static or shared library project
  2. Keep this project in root(cmake) directory and build the library first
  3. Create a build directory at the project root (cmake/testlib)
  4. cd build
  5. Run the command 'cmake ..'
  6. Cmake creates CMakeFiles, CMakeCache.txt, Makefile, cmake_install.cmake in the build directory itself
  7. Run the command 'make'
  8. Application 'testlib' is created by linking either the static or shared
     library.
