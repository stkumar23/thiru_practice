// Modern C++ - C++11 - lambda expression
// Lambda - Anonymous Function
// Syntax: [captureClause] (parameters) -> returnType
//        { statements; }
// The captureClause can be empty. The parameter list can also be empty.
// The return type is optional, and if omitted auto will be assumed.
//
// Compile with -std=c++14
//
// Author: Thiru

#include <iostream>

// main
int main()
{
  auto square = [] (int x) {
    return x*x;
  };

  std::cout<<"Square of 5 is "<<square(5)<<std::endl;
  std::cout<<"Square of 7 is "<<square(7)<<std::endl;

  // Generalized lambda expression, due to use of auto keyword in parameter list
  // auto parameter is allowed in C++14
  auto squareCxx14 = [] (auto x) {
    return x*x;
  };

  std::cout<<"Square of 6 is "<<squareCxx14(6)<<std::endl;
  std::cout<<"Square of 7.2 is "<<squareCxx14(7.2)<<std::endl;

  // Use of static variable in generic lambdas. Unique lambda will be generated
  // for each different type that auto resolves to.
  auto print = [] (auto value) {
    static int callCount{0};
    std::cout<< callCount++ << " : " << value <<std::endl;
  };

  print(1);           // callCount is 0
  print(2);           // callCount is 1

  print("C++11");     // callCount is 0
  print("C++14");     // callCount is 1

  print(3);           // callCount is 2

  return 0;
}
