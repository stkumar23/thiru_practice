// Modern C++ - C++17 - Structured Binding
// Binds the specified names to subobjects or elements of the initializer.
//
// Like a reference, a structured binding is an alias to an existing object.
// Unlike a reference, a structured binding does not have to be of a reference
// type.
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <string>
#include <unordered_map>

struct Employee {
  int id;
  std::string name;

  Employee(int i, std::string s) : id(i), name(s) {}
};

Employee sampledata() {
  return Employee(10, "Sachin");
}

int main()
{
  // binding an array
  int a[2] = {1, 2};
  // number of variables must equal the number of array elements
  auto [first, second] = a; // first is 1 and second is 2
  std::cout<<"First "<<first<<" Second "<<second<<std::endl;

  // binding to data members
  auto [eid, ename] = sampledata();
  std::cout<<"ID: "<<eid<<" Employee Name: "<<ename<<std::endl;


  // Sample use of structured binding and variable declaration in if condition
  std::unordered_map<int, std::string> courses;

  for (int i{2}; i; --i) {
    if (auto [data, success] = courses.insert({101, "Basics of Algorithms"}); success) {
      std::cout<<(*data).second<<" is added into course list"<<std::endl;
    } else {
      std::cout<<(*data).second<<" is already added into course list"<<std::endl;
    }
  }

  return 0;
}
