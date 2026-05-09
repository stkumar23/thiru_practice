// Modern C++ - C++20 - std::span
// 
// std::span - an object (non-owning view) that can refer to a contiguous sequence
// of objects with the first element of the sequence at position zero. It can 
// have either a static extent or dynamic extent. Number of elements in the s
// equence is known at compile-time for static extent.
// It is essentially a lightweight wrapper containing a pointer to the data and its size
//
// Spans are lightweight objects intended to pass by value
// std::span<const T> - used for read only access
// std::span<T> - used for read/write access
//
// Non-Owning: It does not manage memory; the underlying data must outlive the span to avoid dangling references.
// Lightweight: Typically just two words in size (pointer + length), making it efficient to pass by value.
//
// Defined in the header <span>
//
// Usecase: Can be used to pass contiguous sequence to function without specifying the size
//
// Compile with -std=c++20
// 
// Author: Thiru

#include <iostream>
#include <vector>
#include <span>

void display(std::span<const int> seq) {
   for (auto& element: seq) {
      std::cout<<element<<" ";
   }
   std::cout<<std::endl;
}

int main() {
   int arr[] = {11, 12, 13, 14, 15};
   // in case the integral type 5 does not match with arr size, results in compilation error
   std::span<int, 5> s_span {arr}; // using static extent
   display(s_span);

   // you can omit that integral part, it can be considered as dynamic extent
   std::span<int> s1_span {arr}; // using dynamic extent
   display(s1_span);

   // dynamic extent
   std::vector vec {1, 2, 3, 4, 5};
   std::span<int> d_span {vec};
   display(d_span);

   return 0;
}
