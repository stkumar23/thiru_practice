// Design Pattern - Factory Method
// This design pattern decouples the object creation from its implementation
//
// Author: Thiru

#include <iostream>

// Definition of Various Car Type
enum class CarType {
  ICE,
  HYBRID,
  PHEV,
  BEV
};

// Base Class
class Car {
public:
  virtual void getCarType() = 0;
  virtual ~Car(){}
};

// Derived Classes Definitions
class IceCar : public Car {
public:
  void getCarType() override {
    std::cout << "ICE Car"<<std::endl;
  }
};

class HybridCar : public Car {
public:
  void getCarType() override {
    std::cout << "Hybrid Car"<<std::endl;
  }
};

class PhevCar : public Car {
public:
  void getCarType() override {
    std::cout << "PHEV Car"<<std::endl;
  }
};

class BevCar : public Car {
public:
  void getCarType() override {
    std::cout << "BEV Car"<<std::endl;
  }
};

// Factory class definition
// This class creates the object based on the car type
// This class implementation can be updated later to add new definitions
class CarFactory {
public:
  Car* buildCar (CarType cType) {
    switch (cType) {
      case CarType::ICE:
        return new IceCar();
      case CarType::HYBRID:
        return new HybridCar();
      case CarType::PHEV:
        return new PhevCar();
      case CarType::BEV:
        return new BevCar();
      default:
        return nullptr;
    }
  }
};


// Client class
// When new car type is added, this part of code does not need to be
// re-compiled.
class CarClient {
public:
  CarClient() : m_carObject(nullptr) {
  }

  ~CarClient() {
    if (m_carObject) {
      delete m_carObject;
      m_carObject = nullptr;
    }
  }

  void buildCar (CarType cType) {
    CarFactory cf;
    m_carObject = cf.buildCar(cType);
  }

  Car* getCar() {
    return m_carObject;
  }

private:
  Car *m_carObject;
};

// main
int main()
{

  CarClient *cc = new CarClient();

  cc->buildCar(CarType::ICE);
  Car *c1 = cc->getCar();
  if (c1 != nullptr)
    c1->getCarType();

  cc->buildCar(CarType::BEV);
  Car *c2 = cc->getCar();
  if (c2 != nullptr)
    c2->getCarType();

  delete cc;
  cc = nullptr;

  return 0;
}
