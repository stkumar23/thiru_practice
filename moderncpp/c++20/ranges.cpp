// Modern C++ - C++20 - std::ranges
// 
// std::ranges - Ranges are an abstraction that allows a C++ program
// to operate on elements of data structures uniformly. We can look 
// at it as a generalization over the pair of two iterators. Ranges
// offer a more readable and safer alternative to the traditional 
// iterator-pair approach.
//
// Different types of ranges: containers, views, sized ranges, 
// borrowed ranges, bidirectional ranges, forward ranges and more.
//
// Container - It’s a range that owns the elements.
//
// View - This is a range that doesn’t own the elements that the 
// begin/end points to. A view is cheap to create, copy and move.
// They are lazily evaluated, meaning they only process data when 
// you iterate over them.
//
// Defined in the header <ranges>
//
// Compile with -std=c++20
// 
// Author: Thiru

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};

    // using STL iterators, find numbers greater than 4
    auto res = std::find_if(vec.begin(), vec.end(), [](int e) { return e > 4; });
    if (res != vec.end()) {
        std::cout<<"using STL: " << *res << std::endl;
    }

    // using ranges
    auto res1 = std::ranges::find_if(vec, [](int e) { return e > 4; });
    if (res1 != vec.end()) {
        std::cout <<"using ranges : " << *res1 << std::endl; // prints 5
    }

    // views
    // v is a view; creating it neither changes vec, nor does v store any elements.
    // The time it takes to construct v and its size in memory is independent of the size of vec
    auto v = std::views::reverse(vec);
    std::cout << *v.begin() << '\n'; // prints 8
    std::cout << *vec.begin() << '\n'; // prints 1

    return 0;
}