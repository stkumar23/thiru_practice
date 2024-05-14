// Modern C++ - C++17 - init statement in if and switch control structures
//
// A variable (of short scope) can be declared within the if or switch condition
// to avoid naming clash with the outside block.
// The variable is available in the else block as well.
//
// syntax: if (init: condition)
//         switch (init: condition)
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <string>

// main
int main()
{
  const std::string str = "C++17 Features. Hello World";

  // The init statement (const auto it) is placed in the if statement
  // Otherwise, the init statement have to be placed outside if block and
  // care must be taken to avoid naming clash
  if (const auto it = str.find("C++17"); it != std::string::npos)
    std::cout<<"Position of the text C++17 in the str "<<it<<std::endl;

  if (const auto it = str.find("World"); it != std::string::npos)
    std::cout<<"Position of the text World in the str "<<it<<std::endl;

  return 0;
}
