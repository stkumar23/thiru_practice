// Design Pattern - Observer
// Observer design pattern is a behavioral design pattern that allows some
// objects to notify other objects about changes in their state.
//
// Author: Thiru

// Key concepts of this designa pattern
// Subject: This is the object that is being obseved. It maintains a list of
//          observers and notifies them of state changes.
// Observer: The object that is interested in the state changes of subject.
// Concreate subject: Derived from subject class. Responsible for maintaining
//                    the state and notifying observers when changes occur.
// Concreate observer: Derived from observer class. Object that registers with
//                     a concrete subject and react to state changes.

#include <iostream>
#include <vector>

// Observer
class Observer {
public:
  virtual void update(float temp, float humidity, float pressure) = 0;
};

// Concrete Observer
class Display : public Observer {
public:
  Display(unsigned id) : m_id(id) {
  }

  void update(float temp, float humidity, float pressure) override {
    std::cout<<"Display-"<<m_id<<":  Temperature = "<<temp
              <<"C Humidity = "<<humidity
              <<"% Pressure = "<<pressure<<"hPa"<<std::endl;
  }
private:
  unsigned m_id;
};

// Subject
class WeatherStation {
public:
  void registerObserver(Observer* observer) {
    m_observers.push_back(observer);
  }

  void notifyObservers() {
    for (Observer* observer : m_observers) {
      observer->update(m_temperature, m_humidity, m_pressure);
    }
  }

  void setMeasurements(float temp, float hum, float press) {
    m_temperature = temp;
    m_humidity = hum;
    m_pressure = press;
    notifyObservers();
  }

private:
  float m_temperature;
  float m_humidity;
  float m_pressure;
  std::vector<Observer*> m_observers;
};


int main()
{
  WeatherStation ws;

  // display objects
  Display d1(1);
  Display d2(2);

  // register displays as observers
  ws.registerObserver(&d1);
  ws.registerObserver(&d2);

  ws.setMeasurements(19.4, 70, 1008.2);
  ws.setMeasurements(22.1, 55, 1028.7);

  return 0;
}
