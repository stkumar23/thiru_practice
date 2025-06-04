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
#include <type_traits>
#include <string>

// Example - 1
template <typename T>
concept Integral = std::is_integral_v<T>;

// template function to add two given values
// This function ensures that the given arguments are of Integral type
template<typename T>
requires Integral<T>
T add(T a, T b) {
    return a + b;
}

// Example - 2
template <typename T>
concept Multipliable = requires (T a, T b) {
  a * b; // ensure that the given values are multiplicable
};

// template function to multiply two given values
// below function will work for any numeric types
template<typename T>
T multiply(T a, T b) requires Multipliable<T> {
    return a * b;
}


// Example - 3
// Custom concept to check the given argument can be to coverted to string
template <typename T>
concept convertibleToStdString = requires (T a) {
  std::to_string(a);
};

// Using the convertibleToStdString concept, combines two given integer
// values in string format
template <typename T>
auto concatenate(T a, T b) requires convertibleToStdString<T> {
  return std::to_string(a) + std::to_string(b);
}

int main()
{
  int a{3};
  int b{20};
  std::string strnum("40");

  // Using Example - 1
  {
    std::cout<<"Using integer values - add " << add(a, b)<<std::endl;

    // below code will not compile
    // note: candidate: ‘template<class T>  requires  Integral<T> T add(T, T)’
    //std::cout<<"Using integer and string - add " << add(a, strnum)<<std::endl;
  }
  
  // Using Example - 2
  {
    std::cout<<"Using integer values - multiply " << multiply(a, b)<<std::endl;

    // below code will not compile
    // note: candidate: ‘template<class T> T multiply(T, T) requires  Multipliable<T>’
    // T multiply(T a, T b) requires Multipliable<T> {
    // customconcepts.cpp:37:3: note:   template argument deduction/substitution failed:

    //std::cout<<"Using integer and string - multiply " << multiply(a, strnum)<<std::endl;
  }

  // Using Example - 3
  std::cout<<"Using string values - concatenate " << concatenate(a, b)<<std::endl;


  return 0;
}