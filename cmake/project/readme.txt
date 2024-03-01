Sample cmake project
  1. CMakeLists.txt at root lists the project executable name,
    the inc and src directories
  2. CMakeLists.txt in the src directory adds the source files to the target


How to build the project:
  1. Create a build directory at the project root (cmake/project)
  2. cd build
  3. Run the command 'cmake ..'
  4. Cmake creates CMakeFiles, CMakeCache.txt, Makefile, cmake_install.cmake in the build directory itself
  5. Run the command 'make'
  6. Executable 'project' is created in the build directory
  7. Run the executable 'project'
