// Modern C++ - C++17 - Multiple new algorithms
// std::gcd - returns the greatest common divisor of two integers.
//            Defined in <numeric>
// std::lcm - returns the least common multiple of two integers.
//            Defined in <numeric>
// std::clamp(v, low, high) - returns the value of v, otherwise returns the
//                            nearest boundary. Defined in <algorithm>
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <numeric>
#include <algorithm>

int main() {

  int num1 = 5;
  int num2 = 12;

  std::cout<<"gcd of "<<num1<<" and "<<num2<<" is "
            <<std::gcd(num1, num2)<<std::endl;

  std::cout<<"lcm of "<<num1<<" and "<<num2<<" is "
            <<std::lcm(num1, num2)<<std::endl;

  // returns 10, which is between the range 5 to 12.
  std::cout<<"clamp(10, 5, 12) is "<<std::clamp(10, num1, num2)<<std::endl;

  // returns 5, because 1 is lesser than the minimum range 5.
  std::cout<<"clamp(1, 5, 12) is "<<std::clamp(1, num1, num2)<<std::endl;

  // returns 12, because 14 is greater than the maximum range 12.
  std::cout<<"clamp(14, 5, 12) is "<<std::clamp(14, num1, num2)<<std::endl;

  return 0;
}
