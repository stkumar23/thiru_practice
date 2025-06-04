// Modern C++ - C++20 - Concepts
// Concept is a set of constraints on template parameters evaluated at compile time.
// Use the keywords requires or concept
//
// Defined in the header <concepts>
//
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>
#include <concepts>

// template function to multiply two given values
// below function will work for any numeric types
template<typename T>
T multiply_1(T a, T b) {
    return a * b;
}

// Using requires
// template function to multiply two given values
// below function will work for any numeric types
template<typename T>
requires std::integral<T>
T multiply_2(T a, T b) {
    return a * b;
}

// // multiply_2 function can also be written below (various use of requires)
// template<typename T>
// T multiply_3(T a, T b) requires std::integral<T> {
//     return a * b;
// }

// // in place of template typename
// template<std::integral T>
// T multiply_4(T a, T b) {
//     return a * b;
// }


int main()
{
  int a{2};
  int b{20};

  float c{1};
  float d{2};

  std::cout<<"Using template function-1 " << multiply_1(a, b)<<std::endl;
  std::cout<<"Using template function-1 " << multiply_1(c, d)<<std::endl;   // works

  //std::cout<<"Using template function-2 " << multiply_2(a, b)<<std::endl;

  // below code will not compile
  // because the variables c and d are not of integral type, compiler will throw error
  // candidate: ‘template<class T>  requires  integral<T> T multiply_2(T, T)’

  //std::cout<<"Using template function-2 " << multiply_2(c, d)<<std::endl;

  return 0;
}
