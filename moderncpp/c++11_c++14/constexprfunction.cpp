// Modern C++ - C++11 and C++14 - constexpr function
// Functions can be marked with constexpr keyword, they can be evaluated
// at compile time.
// C++11: Only one return statement can present inside the constexpr function
//        No other statements, blocks are not allowed, even local declaration
// C++14: Relaxed C++11 restrictions. Control structures, multiple return
//        statements, multiple if statements, local variable declarations are
//        allowed (except static, thread local variables), variables should be
//        initialized.
// Compile with -std=c++14
//
// Author: Thiru

#include <iostream>

// C++11
constexpr int square(int x) {
  return x*x;
}

// C++11
constexpr int factorial(int n) {
  return n<=1 ? 1 : (n*factorial(n-1));
}

// C++14
constexpr int factorialCxx14(int n) {
  int res = 1; // compile error without initialization
  while(n>1) {
    res *= n--;
  }
  return res;
}

int main()
{
  constexpr int squ5 = square(5); // squ5 value is known at compile time
  std::cout<<"Value of swu5 is "<<squ5<<std::endl;

  constexpr int fact = factorial(5); // fact value is known at compile time
  std::cout<<"Value of fact is "<<fact<<std::endl;

  constexpr int factCxx14 = factorialCxx14(5);
  std::cout<<"Value of factCxx14 is "<<factCxx14<<std::endl;

  return 0;
}
