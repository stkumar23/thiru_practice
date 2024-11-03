// Modern C++ - C++20 - Three way comparison operator
// The expresssion a <=> b returns an object such that
//    (a <=> b) < 0 if a < b
//    (a <=> b) > 0 if a > b
//    (a <=> b) == 0 if a and b are equal
// Defined in the header <compare>
//
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>
#include <compare>

int main()
{
  int a = 2;
  int b = 20;

  auto res = a <=> b;

  if (res < 0) {
    std::cout<<" a is less than b"<<std::endl;
  } else if (res > 0) {
    std::cout<<" a is greater than b"<<std::endl;
  } else  if (res == 0) {
    std::cout<<" both a and b are same"<<std::endl;
  } else {
    std::cout<<" a or b are unordered"<<std::endl;
  }

  return 0;
}
