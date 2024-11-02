// Modern C++ - C++11 - std::bind and std::placeholders
// std::bind - Function template generates a forwarding call wrapper for a
// function. Calling this wrapper is equivalent to invoking the function with
// some of its arguments bound to args.
//
// std::placeholders _1, _2, _3, ... are used as args binding.
//
// Compile with -std=c++11
//
// Author: Thiru

#include <iostream>
#include <functional>
#include <string>

void printName(const std::string& sName) {
  std::cout<<"Hello "<<sName<<std::endl;
}

int getSum(int val1, int val2, int val3) {
  return val1 + val2 + val3;
}

int netValue(int val1, int val2, int val3) {
  return val1 - val2 - val3;
}

// main
int main()
{
  // f is the wrapper for the function printName, as it accepts a single
  // arguments represented by std::placeholders::_1
  auto f = std::bind(&printName, std::placeholders::_1);
  f("Kavin");

  // the order defines the postion of the arguments
  auto sFn = std::bind(&getSum, std::placeholders::_1,
            std::placeholders::_2,
            std::placeholders::_3);

  std::cout<<"The sum is "<<sFn(2, 3, 5)<<std::endl;

  // the placeholder order defines the postion of the arguments
  auto nFn = std::bind(&netValue, std::placeholders::_2,
            std::placeholders::_1,
            std::placeholders::_3);

  std::cout<<"The netvalue is "<<nFn(2, 5, 3)<<std::endl; // 5 - 2 - 3 = 0
  std::cout<<"The netvalue is "<<nFn(1, 10, 4)<<std::endl; // 10 - 1 - 4 = 5

  return 0;
}
