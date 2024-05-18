// Modern C++ - C++17 - std::string_view
// std::string_view - Provides read-only access to an existing string without
// making a copy.
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <string_view>

// str provides read-only access to the argumenr passed-in
// It does not makes a copy of it. In case the function is defined like below
// str makes a copy of its initializer, which is inefficient.
// void printString(std::string str) {

void printString(std::string_view str) {
  std::cout<<"The string is "<<str<<std::endl;
}

//main
int main()
{
  std::string_view s{"C++17 - string_view"};
  printString(s);

  return 0;
}
