// Modern c++ - c++17 - std::variant
// The class template std::variant represents a type-safe union
// At any given time, it can holds a value of one of its alternative types,
// or in case of error - no value.
// std::variant simplifies handling multiple possible types in a type-safe way.
// std::variant allows you to safely manage and work with different types,
// reducing the complexity and improving the safety of your code.
// A variant is not permitted to hold references, arrays, or the type void.
//
// Defined in the header <variant>
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <string>
#include <variant>

// Sample variant type definition
using SampleVariant = std::variant<int, std::string>;

void printvalue(const SampleVariant& sv) {
  // std::visit is also defined in the header <variant>
  // std::visit takes the variant and prints the value based on type
  std::visit([](auto&& arg) { std::cout << arg << std::endl; }, sv);
}

int main() {
  SampleVariant s {95};
  printvalue(s);

  s = "Hello World";
  printvalue(s);

  return 0;
}
