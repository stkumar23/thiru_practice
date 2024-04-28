// Design Pattern - Adapter
// This structural design pattern allows incompatible objects to collaborate.
//
// Author: Thiru

#include <iostream>
#include <string>
#include <algorithm>

class Target {
public:
  virtual ~Target() = default;
  virtual std::string request() const {
    return "Target: Default's Target behavior";
  }
};

class Adaptee {
public:
  std::string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

class Adapter : public Target {
  Adaptee *m_adaptee = nullptr;
public:
  Adapter(Adaptee *adaptee) : m_adaptee(adaptee) {
  }

  std::string request() const override {
    std::string to_reverse = m_adaptee->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: TRANSLATED - " + to_reverse;
  }
};

void clientCode(const Target* target) {
  std::cout<<target->request()<<std::endl;
}

// main
int main()
{
  Target *t = new Target();
  clientCode(t);

  Adaptee *a = new Adaptee();
  std::cout<<"Adaptee: "<<a->SpecificRequest()<<std::endl;

  Adapter *aptr = new Adapter(a);
  clientCode(aptr);

  delete t;
  delete a;
  delete aptr;

  return 0;
}
