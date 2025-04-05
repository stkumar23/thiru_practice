// simple program to check whether a given number is of single digit or not
// This is to demo gtest

#include <iostream>
#include "checknumdigits.h"

// Function checks whether the given number is a single digit or double.
bool CheckDigit::isSingleDigit(const int& num) {
  if (num >= 1 && num < 10) {
    std::cout<<num<<" is Single digit"<<std::endl;
    return true;
  } else if (num >= 10 && num < 100) {
    std::cout<<num<<" is Double digit"<<std::endl;
  } else {
    std::cout<<"Incorrect number"<<std::endl;
  }
  return false;
}
