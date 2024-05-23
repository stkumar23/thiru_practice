// Modern C++ - C++17 - constexpr if
// constexpr if - If  the condition is true, the else part is discarded at
// compile time, otherwise, the if block is discarded. Something like static if.
// syntax: if constexpr (condition) statements else statements
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <memory>

template <int n>
constexpr int fact() {
  if constexpr (n == 1)
    return 1;
  else
    return n * fact<n-1>();
}

template <typename T>
auto get_value(T t) {
  if constexpr (std::is_pointer_v<T>)
    return *t;
  else
    return t;
}

// main
int main()
{
  std::cout<<"Factorial of 5 "<<fact<5>()<<std::endl;

  auto p = std::make_unique<int>(8);
  int i = 10;

  std::cout<<"*p "<<get_value(p.get())<<std::endl;
  std::cout<<"i "<<get_value(i)<<std::endl;

  return 0;
}
