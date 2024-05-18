// Modern C++ - C++11 - thread
// The class thread represents a single thread of execution. It allows multiple
// functions to execute concurrently.
// Five different ways to define thread function:
//        1) Normal thread function, 2) lambda function, 3) funtion object,
//        4) non-static member and 5) statitc member functions
//
// Compile with -std=c++11 -lpthread
//
// Author: Thiru

#include <iostream>
#include <thread>

// normal thread function
void regularThreadFunction(int a) {
  std::cout<<"Regular thread function "<<a<<std::endl;
}

// using function object/functor
class threadFunctor {
public:
    void operator() (int a) {
      std::cout<<"Functor thread function "<<a<<std::endl;
    }
};


// using non-static member function
class SampleThread {
public:
    void print(int a) {
      std::cout<<"Non-static thread member function "<<a<<std::endl;
    }
};

// using static member function
class StaticThread {
public:
    static void print(int a) {
      std::cout<<"Static thread member function "<<a<<std::endl;
    }
};

// main
int main()
{
  // lambda thread function
  auto lambdaTh = [] (int a) {
    std::cout<<"Lambda thread function "<<a<<std::endl;
  };

  std::thread nT(regularThreadFunction, 10);
  nT.join();

  std::thread lT(lambdaTh, 20);
  lT.join();

  std::thread fT(threadFunctor(), 30);
  fT.join();

  SampleThread obj;
  std::thread nsT(&SampleThread::print, obj, 40);
  nsT.join();

  std::thread sT(&StaticThread::print, 50);
  sT.join();

  return 0;
}
