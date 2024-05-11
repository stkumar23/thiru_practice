// Modern C++ - C++14 - lambda init capture
// Lambda - capture initializers
// The captureClause is used to give a lambda access to variables available in
// the surrounding scope that it normally would not have access to.
// By default, the captues are treated as const by default.
// Use mutable to modify the variables that were captured.
// Initialize variables in the capture if their value is short and their type is
// obvious. These init variables are only visible in the scope of the lambda.
//
// Compile with -std=c++14
//
// Author: Thiru

#include <iostream>

int area(int r) {
  return r*r;
}

// main
int main()
{
  // x is init capture varaible, visible only within the lambda
  auto circleArea = [x = area(8)] () { return x; };

  std::cout<<circleArea()<<std::endl;
  //std::cout<<x; // error. x is not visible outside lambda

  auto increment = [i = 0] () mutable { return i++; };

  std::cout<<increment()<<std::endl;
  std::cout<<increment()<<std::endl;
  std::cout<<increment()<<std::endl;

  return 0;
}
