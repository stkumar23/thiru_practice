// Modern C++ - C++11 - Override and Final
// overide - Declare overriding functions override
// final   - Prevents overriding for both function and class
//
// Author: Thiru
//
// Compile with -std=c++14
//
// override:
// Declare overriding functions override

// final:
// Applying final to a virtual function prevents the function from being
// overridden in derived classes.
// It can also be applied to a class, in which case the class is prohibited
// from being used as a base class.

#include <iostream>
#include <memory>

class Base {
public:
  virtual void print() {
    std::cout<<"This is from base class"<<std::endl;
  }

  virtual void getClassName() final {
    std::cout<<"Base"<<std::endl;
  }
};

class Derived final : public Base {
public:
  // compiler throws error when the base function signature is modified
  // Otherwise compiler wont show any error
  void print() override { // virtual keyword is optional
    std::cout<<"This is from Derived class"<<std::endl;
  }

  // Below function cannot be overridden, because it is declared as final in
  // the base class. Compiler error.
  // void getClassName() {
  //   std::cout<<"Derived"<<std::endl;
  // }
};

// Below class cannot use Derived as base class, due to final declaration
// compiler will show error
// class NewDerived : public Derived {
// };

// main
int main()
{
  std::unique_ptr<Base> b = std::make_unique<Derived>();
  b->print();
  b->getClassName();

  return 0;
}
