// Modern C++ - C++11 - std::chrono::time_point
// time_point - To express particular point in time. It is implemented as if it
// stores a value of type Duration indicating the time interval from the start
// of the Clock's epoch.
//
// Defined in the header <chrono>
// Compile with -std=c++11
//
// Author: Thiru

#include <iostream>
#include <chrono>

// function to find the Factorial
constexpr int factorial(int n) {
  return n<=1 ? 1 : (n*factorial(n-1));
}

//main
int main()
{
  // Using steady_clock and time_point
  std::chrono::time_point<std::chrono::steady_clock> start, end;

  // Note down start and end time_points
  start = std::chrono::steady_clock::now();
  std::cout<<"Factorial of 23 is "<<factorial(23)<<std::endl;
  end = std::chrono::steady_clock::now();

  // Find the elapsed time in nanoseconds
  std::chrono::nanoseconds elapsedTime = end - start;
  std::cout<<"Elapsed time in ns: "<<elapsedTime.count()<<std::endl;

  return 0;
}
