// Modern C++ - C++11 - Member function const
// Make const member functions thread safe. In case the const member
// function does any write operation, make it thread safe for well defined
// behavior. Compile with -lpthread
//
// Author: Thiru
//
// Use std::atomic to manipulate single variable or memory location in a
// const function. To manipulate multiple variables in the such function,
// use mutex

#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>

class Sample {
public:
  Sample (int x, int y) : m_x(x), m_y(y) {
  }

  void getCounterValue() const noexcept {
    ++m_counter;
    std::cout<<"Counter: "<<m_counter<<std::endl;
  }

  void getSum() const {
    std::lock_guard<std::mutex> lg(m);
    // this block will be executed only once when multiple threads are called
    if (!m_calculated) {
      m_sum = m_x+m_y;
      m_calculated = true;
    }
    std::cout<<"Sum: "<<m_sum<<std::endl;
  }

private:
  mutable std::atomic<unsigned> m_counter{0};
  mutable bool m_calculated {false};
  mutable int m_sum{0};
  mutable std::mutex m;
  int m_x;
  int m_y;
};

int main()
{
  Sample s(5,10);

  std::thread t1(&Sample::getSum, &s);
  std::thread t2(&Sample::getSum, &s);
  t1.join();
  t2.join();

  std::thread t3(&Sample::getCounterValue, &s);
  std::thread t4(&Sample::getCounterValue, &s);
  t3.join();
  t4.join();

  return 0;
}
