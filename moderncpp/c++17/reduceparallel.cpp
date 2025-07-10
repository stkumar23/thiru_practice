// Modern C++ - C++17 - std::reduce
// std::reduce is designed for parallel execution. It is similar
// to std::accumulate except the elements of the range may be
// grouped and rearranged in arbitrary order.
//
// std::accumulate() guarantees that the operands are combined in
// the order they appear in the range. This strict ordering means
// that each element must be processed one after the other, which
// inherently prevents parallel execution.
//
// Defined in the header <numeric>
// To compile program using std::reduce, use Intel's
// Thread Building Block library (libtbb)
//
// Compile with -ltbb -std=c++17
//
// Author: Thiru

#include <iostream>
#include <vector>
#include <numeric>
#include <execution> // For execution policy
#include <chrono>

int main() {
  std::vector<int> nums(1000000, 1);

  auto start = std::chrono::steady_clock::now();
  // Sum all the elements in the vector nums
  int result = std::accumulate(nums.begin(), nums.end(), 0);
  auto end = std::chrono::steady_clock::now();

  std::cout << "(Sequential execution) Result: " << result << std::endl;
  std::cout << "Computed the result in "
            << std::chrono::duration<double, std::milli> (end - start).count()
            << " ms" << std::endl;

  start = std::chrono::steady_clock::now();
  // Sum all the elements in the vector nums
  result = std::reduce(std::execution::par,
                      nums.begin(), nums.end(), 0);
  end = std::chrono::steady_clock::now();

  std::cout << "(Parallel execution) Result: " << result << std::endl;
  std::cout << "Computed the result in "
            << std::chrono::duration<double, std::milli> (end - start).count()
            << " ms" << std::endl;

  return 0;
}
