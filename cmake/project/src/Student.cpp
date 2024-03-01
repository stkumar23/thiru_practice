#include <Student.h>

Student::Student(int no, std::string name, std::string degree):
  m_rollNo(no), m_name(name), m_degree(degree) {
}

void Student::print() {
  std::cout << "Student details are:" << '\n';
  std::cout << "\tRoll No: " << m_rollNo << '\n';
  std::cout << "\tName: " << m_name << '\n';
  std::cout << "\tDegree: " << m_degree << '\n';
}
