#include <iostream>

class Student {
public:
  Student() = default;
  Student(int no, std::string name, std::string degree);
  void print();

private:
  int m_rollNo;
  std::string m_name;
  std::string m_degree;
};
