// Modern C++ - C++20 - Modules
// Modules are a language features. This helps the dependency management is
// done during the compilation, instead of preprocessing and linking like in
// headers. The undefined references are identified during the compilation
// stage itself instead of delaying till linking (the normal way using headers).
// Module units are compiled only once. In constrast, a header file is
// recompiledon every translation unit that includes it.
//
// Compilation: g++ -std=c++2a -c samplemodule.cpp -fmodules-ts -o samplemodule.o
//
// Modular compilation is not enabled with just the -std=c++20 option.
// You must explicitly enable it with the -fmodules-ts option. 
// Author: Thiru

// Global module fragment. This is used to include headers when
// importing the headers is not possible. First declaration must be module
module;
// now include preprocessing directives like headers
#include <iostream>
// end of global module fragment section

// Module Declaration creates a module unit
export module sample;

// Namespaces and modules are orthogonal: one module can have multiple
// namespaces, and the same namespace might exist across multiple modules.
namespace samplenamespace {
  // function is not exported which can't be accessed outside the module
  int add (int a, int b) {
    return a+b;
  }

  // this function is exported which can be accessed outside the module
  export void printFunction() {
    std::cout<<"Print Function, exported in the module"<<std::endl;
  }
} // namespace samplenamespace
