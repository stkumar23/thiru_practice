// Modern C++ - C++23 - std::flat_set
// 
// std::flat_set is an associative container designed to store
// unique elements in sorted order, simialr to std::set, but it origanizes all
// its elements in a contiguous block of memeory.
// The container maintains its elements in sorted order based on their keys
// std::flat_map is ideal for static or rarely changing datasets that are frequently queried
//
// Pros:
// Better Performance: Because elements are stored in a single block, the CPU can access 
// data more quickly. This is especially noticeable when iterating through the set or 
// performing lookups.
// Less Memory: It uses less memory than std::set by avoiding the overhead of pointers 
// and separate memory allocations for each element.
//
// Cons:
// Slower Changes: Adding or removing elements can be slow. Because the elements must 
// stay sorted, inserting or deleting an item in the middle requires shifting all the 
// elements that come after it.
// Iterator Issues: If you add or remove elements, any existing iterators or references 
// you have to the set’s elements may become invalid, which can cause bugs if you’re not careful.
//
// Use cases
// Small to medium-sized sets where the cost of O(N) modifications is acceptable or 
// modifications are infrequent.
// Read-heavy data sets where fast iteration and lookups are paramount.
//
// Defined in the header <flat_set>
//
// Compile with -std=c++23
// 
// Author: Thiru


#include <flat_set>
#include <print> // for std::println

int main() {
   std::flat_set<int> user_ids;

   records.insert(2);
   records.insert(3);
   records.insert(5);
   records.insert(1);
   records.insert(4);

   for(const auto& id : user_ids) {
      std::println(id);
   }

   return 0;
}
