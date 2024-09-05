// Modern C++ - C++11 - std::future
// Use of std::future and std::async. Defined in header <future>
//
// std::future is a class template used to receive the result of an
// asynchronously executed task that is not computed yet, ie. future value.
// std::future can also be used with std::promise or std::packaged_task
//
// std::async helps in managing asynchronous operations
//
// Compile with -std=c++11 -lpthread
//
// Author: Thiru

#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main()
{
  std::future<int> f = std::async(std::launch::async, [](){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 21;
  });

  // future value can be read only once.
  // use f.valid() if the object has a shared state, ie. valid to use get()
  std::cout<<f.get()<<std::endl;

  return 0;
}
