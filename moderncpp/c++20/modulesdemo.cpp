// Modern C++ - C++20 - Modules
// Modules demo program
//
// Compilation: First compile the samplemodule.cpp
// Compilation: g++ -std=c++2a -c modulesdemo.cpp -fmodules-ts -o modulesdemo.o
// g++ -std=c++2a -c modulesdemo.o samplemodule.o -o module_demo

// sample module is imported
import sample;

int main() {

  // Works. accessing an exported symbol
  samplenamespace::printFunction();

  // Error. accessing non-exported symbol
  //samplenamespace::add(1, 6);

  return 0;
}
