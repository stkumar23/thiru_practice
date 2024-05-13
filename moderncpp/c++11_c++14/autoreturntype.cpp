// Modern C++ - C++11 - auto function trailing return type
// Trailing return type
// The trailing return type should be specified while using auto return type in
// the function. This is to deduce the return type of the function. This is
// must in C++11.
// With C++14, this trailing return type is not required. It automatically
// deduces the function return type.
//
// Compile with -std=c++14
//
// Author: Thiru

#include <iostream>

// C++11 trailing return type is must for auto return type
auto square(int x) -> int
{
  return x * x;
}

// C++14 trailing return type is not required
auto squareCxx14(int x)
{
  return x * x;
}

// main
int main()
{
  // C++11
  std::cout<<"Square of 4 is "<<square(4)<<std::endl;

  // C++14
  std::cout<<"Square of 9 is "<<squareCxx14(9)<<std::endl;

  return 0;
}
