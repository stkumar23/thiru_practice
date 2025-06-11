// Modern C++ - C++11 - std::packaged_task
// The class template std::packaged_task wraps any Callable target (function, 
// lambda expression, bind expression, or another function object) so that it 
// can be invoked asynchronously. Concept is a set of constraints on template 
// parameters evaluated at compile time.
// Its return value or exception thrown is stored in a shared state which can 
// be accessed through std::future objects. 
//
// Defined in the header <future>
//
// Compile with -std=c++11
//
// Author: Thiru


#include <iostream>
#include <cmath>
#include <iomanip>
#include <future>
#include <exception>

// Function to calculate pi using Gregory-Leibniz Series
double calculate_pi(const int& terms) {
  if (terms < 1) {
    // throws exception in case the terms is 0 or lesser
    throw std::runtime_error("Terms cannot be less than 1");
  }

  double sum = 0.0;

  for (int i=0; i<terms; i++) {
    int sign = pow(-1, i);
    double term = 1.0/(i*2 + 1);
    sum += sign * term;
  }

  return sum * 4;
}

// main
int main()
{
  std::packaged_task<double(int)> task(calculate_pi);
  std::future<double> res = task.get_future();

  std::thread t1(std::move(task), 1E7); // 1E7 - 1*pow(10, 7)

  try {
    std::cout<< "pi " << std::setprecision(15) << res.get() <<std::endl;
  } catch (const std::exception &e) {
    std::cout<<"Exception "<<e.what()<<std::endl;
  }

  t1.join();

  return 0;
}
