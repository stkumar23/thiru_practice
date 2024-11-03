// Modern C++ - C++20 - std::string new functions
// starts_with() - returns true if the string begins with the given prefix
//
// ends_with() - returns true if the string ends with the given suffix
//
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>
#include <string_view>

int main() {
  std::string_view s1{"github repository"};
  std::string_view s2{"github.com"};

  if (s1.starts_with("git")) {
    std::cout<<"string starts with git"<<std::endl;
  } else {
    std::cout<<"string does not have the prefix git"<<std::endl;
  }

  if (s2.ends_with(".com")) {
    std::cout<<"string has the suffix .com"<<std::endl;
  } else {
    std::cout<<"string does not end with .com"<<std::endl;
  }

  return 0;
}
