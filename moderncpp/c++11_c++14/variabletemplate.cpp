// Modern C++ - C++14 - Variable Template
// Variable template defines a family of variables or static data members
//
// Compile with -std=c++14
//
// Author: Thiru

// Variable template provides a way to write the generic code that will
// work for different data types

#include <iostream>

// variable template to define the constant PI
template<class T>
constexpr T pi = T(3.14159265);

// class static data member
class limits {
public:
  template<class T> static constexpr T min = T(10.24);
};

int main()
{
  std::cout<<"Integer version of pi "<<pi<int><<std::endl;
  std::cout<<"Double version of pi "<<pi<double><<std::endl;

  std::cout<<"limits::min<int> "<<limits::min<int><<std::endl;
  std::cout<<"limits::min<double> "<<limits::min<double><<std::endl;

  return 0;
}
