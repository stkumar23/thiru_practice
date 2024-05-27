// Modern C++ - C++11 - std::move
// std::move - allowing the efficient transfer of resources from one object to
// another. It helps avoiding expensive copying.
//
// Defined in the header <utility>
// Compile with -std=c++11
//
// Author: Thiru

#include <iostream>
#include <utility>
#include <vector>

// Function to swap two objects (without move functionality)
// Uses temp object for deep copying
template <typename T>
void swap(T &lhs, T &rhs) {
  T temp = lhs;
  lhs = rhs;
  rhs = temp;
}

// Function to swap two objects (withmove functionality)
// std::move eliminates deep copying
template <typename T>
void swapcpp11(T &lhs, T &rhs) {
  T temp = std::move(lhs);
  lhs = std::move(rhs);
  rhs = std::move(temp);
}

template <typename T>
void printContainer(T container) {
  for(const auto& e: container) {
    std::cout<<e<<" ";
  }
  std::cout<<std::endl;
}

// main
int main()
{
  std::vector<int> v1{1,2,3,4,5,6,7,8,9,10};
  std::vector<int> v2{11,12,13,14,15,16,17,18,19,20};

  swap(v1, v2);
  printContainer(v1);
  printContainer(v2);

  swapcpp11(v1, v2);
  printContainer(v1);
  printContainer(v2);

  // vector swapping can also be achieved by v1.swap(v2);

  return 0;
}
