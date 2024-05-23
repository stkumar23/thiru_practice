// Modern C++ - C++17 - inline variables
// With C++17, variables can be declared inline like how funcions are declared
// inline, inside a header file.
// constexpr variables are inline implicitly. The advantage over constexpr is
// that your initialization expression doesn't have to be constexpr.
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>

struct Sample
{
    inline static const int sValue = 7;
};

// main
int main()
{
  std::cout<<"Sample sValue "<< Sample::sValue<<std::endl;
  return 0;
}
