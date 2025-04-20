// Modern C++ - C++20 - Designated initializers
//
// This helps to improve the readability. syntax:
// T object = { .des1 = arg1 , .des2 { arg2 } ... };
// T object { .des1 = arg1 , .des2 { arg2 } ... };
//
// Each designator must name a direct non-static data member of T, and all
// designators used in the expression must appear in the same order as the data
// members of T.
//
// It works only for aggregate initialization, support only aggregate types (ie.)
// for types with no user defined constructors. Only non-static data members.
// out-of-order designated initialization, nested designated initialization,
// mixing of designated initializers and regular initializers, and designated
// initialization of arrays are all not supported.
// struct A { int x, y; };
// struct B { struct A a; };
//
// struct A a = {.y = 1, .x = 2}; // valid C, invalid C++ (out of order)
// int arr[3] = {[1] = 5};        // valid C, invalid C++ (array)
// struct B b = {.a.x = 0};       // valid C, invalid C++ (nested)
// struct A a = {.x = 1, 2};      // valid C, invalid C++ (mixed)
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>

// Sample type
struct Date {
    int day;
    int month;
    int year;
};

int main()
{
  Date today = { .day{20}, .month{04}, .year = 2025 };

  std::cout<<"Today is "
            <<today.day<<"-"<<today.month<<"-"<<today.year<<std::endl;
  return 0;
}
