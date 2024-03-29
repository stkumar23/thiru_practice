// Design Pattern - Singleton
// Creates only one object of its kind, provides single point of access
// Only one instance of a class can be created
// Constructor is private
// Use -std=c++11 and -lpthread for compilation

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Singleton {

public:
  // Singleton should not be cloneable
  Singleton(Singleton &other) = delete;

  // Singleton should not be assignable
  void operator=(const Singleton &) = delete;

  static Singleton* getInstance(const std::string& name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_instance == nullptr) {
      m_instance = new Singleton(name);
    }
    return m_instance;
  }

  void getName() {
    std::cout<<"Object name: "<<m_name<<std::endl;
  }

private:
  Singleton(const std::string& name) : m_name(name) {
  }

  ~Singleton(){
  }

  static Singleton *m_instance;
  static std::mutex m_mutex;
  std::string m_name;
};

Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;

// Thread funtion to demonstrate Singleton
void ThreadFirst() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* sInst = Singleton::getInstance("ONCE");
  sInst->getName();
}

// Thread funtion to demonstrate Singleton
void ThreadSecond() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* sInst = Singleton::getInstance("TWICE");
  sInst->getName();
}

// main
int main()
{
  std::thread t1(ThreadFirst);
  std::thread t2(ThreadSecond);

  t1.join();
  t2.join();

  return 0;
}
