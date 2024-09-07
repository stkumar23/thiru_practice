// Modern C++ - C++11 - std::promise
// Use of std::future and std::promise. Defined in header <future>
//
// std::future is a class template used to receive the result of an
// asynchronously executed task that is not computed yet, ie. future value.
// std::future can also be used with std::async or std::packaged_task
// It is an asynchronous return object that can retrieve the value of the
// shared state.
//
// std::promise is an object that can store a value of type T to be retrieved
// by std::future object. It is a asynchronous provider and is expected to set
// a value for the shared state at some point.
//
// Compile with -std=c++11 -lpthread
//
// Author: Thiru

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>

int main()
{
  std::promise<std::string> prom;
  auto producer = std::thread([&] {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    prom.set_value("Hello");
  });

  auto future = prom.get_future();
  auto consumer = std::thread([&] {
    std::cout<<future.get().c_str()<<std::endl;
  });

  producer.join();
  consumer.join();

  return 0;
}
