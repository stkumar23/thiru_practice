// Modern C++ - C++14 - std::exchange
// Use of std::exchange function. Defined in header <utility>
//
// Compile with -std=c++14
//
// Author: Thiru

#include <iostream>
#include <vector>
#include <utility>

void myf1() {
  std::cout<<"myf1"<<std::endl;
}

void myf2() {
  std::cout<<"myf2"<<std::endl;
}

int main()
{
  int x = 10;
  int y = 20;
  y = std::exchange(x, y); // now x has the value of y and y has that of x
  std::cout<<"x="<<x<<" y="<<y<<std::endl;

  // to swap values of obe list with another
  std::vector<int> v1{1,2,3,4,5};
  std::vector<int> v2{6,7,8,9,10};

  v2 = std::exchange(v1, v2);
  for(const auto& e: v1) {
    std::cout<<e<<" ";
  }
  std::cout<<std::endl;

  // Fibonacci sequence upto 100
  for (int a{0}, b{1}; a<100; a = std::exchange(b, a+b)) {
    std::cout<<a<<", ";
  }
  std::cout<<std::endl;

  void (*f)();
  std::exchange(f, myf1); // f now points to myf1 function
  f();

  std::exchange(f, myf2); // f now points to myf2 function
  f();

  return 0;
}
