// Modern C++ - C++23 - std::flat_map
//
// std::flat_map is an associative container designed to store
// key-value pairs, much like std::map, but it origanizes all
// its elements in a contiguous block of memeory.
// The container maintains its elements in sorted order based on their keys
// std::flat_map is ideal for static or rarely changing datasets that are frequently queried
//
// Pros:
// Cache Locality: Storing elements close together means that accessing one item often loads
// nearby items into the CPU’s cache, leading to faster access during lookups and iteration.
// Memory Efficiency: It uses less memory than std::map because it avoids the overhead of
// pointers and per-node memory allocations.
// Predictable Performance: For smaller maps, its cache-friendly design can lead to more
// consistent and often faster performance for common operations.
//
// Cons:
// Slow Insertions and Deletions: Adding or removing an element requires shifting subsequent
// elements, which is an O(N) operation. This can be significantly slower than std::map's O(logN) time.
// Iterator Invalidation: Insertions and deletions can invalidate iterators and references, requiring careful handling.
// Costly Reallocations: The container may need to perform a costly reallocation and copy all elements when it runs out of capacity.
//
// Use cases
// You have small to medium-sized maps where the O(N) insertion/deletion cost is acceptable or modifications are infrequent.
//
// Defined in the header <flat_map>
//
// Compile with -std=c++23
//
// Author: Thiru


#include <print> // for std::println
#include <string>
#include <flat_map>

int main() {
   std::flat_map<int, std::string> records;

   records.insert({2, "Kumar"});
   records.insert({3, "Kavin"});
   records.insert({5, "Arul"});
   records.insert({1, "Devi"});
   records.insert({4, "Sandy"});

   for(const auto& [id, name] : records) {
      std::println("ID: {} - Name: {}", id, name);
   }

   return 0;
}
