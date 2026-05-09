// Modern C++ - C++23 - std::mdspan
// 
// std::mdspan - is a multidimensional array view that maps a multidimensional index 
// to an element of the array. The mapping and element access policies are configurable, 
// and the underlying array need not be contiguous or even exist in memory at all.
//
// Defined in the header <mdspan>
//
// Compile with -std=c++23
// 
// Author: Thiru

#include <print>
#include <vector>
#include <mdspan>

int main() {
   std::vector vec{11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

   // 2D array
   auto md2Dspan = std::mdspan(vec.data(), 2, 6);
   // rank represents the array dimension
   std::println("md2Dspan rank {} ext 0: {} ext 1: {}", md2Dspan.rank(), md2Dspan.extent(0), md2Dspan.extent(1));
   // outputs md2Dspan rank 2 ext 0: 2 ext 1: 6

   for (std::size_t i=0; i!= md2Dspan.extent(0); i++) {
      for (std::size_t j=0; j!= md2Dspan.extent(1); j++) {
          std::print("{} ", md2Dspan[i, j]);
      }
      std::println("");
   }

   // 3D array
   auto md3Dspan = std::mdspan(vec.data(), 2, 3, 2);
   std::println("md3Dspan rank {} ext 0: {} ext 1: {} ext 2: {}", 
            md3Dspan.rank(), md3Dspan.extent(0), md3Dspan.extent(1), md3Dspan.extent(2));
   // md3Dspan rank 3 ext 0: 2 ext 1: 3 ext 2: 2

   for (std::size_t i=0; i!= md3Dspan.extent(0); i++) {
      for (std::size_t j=0; j!= md3Dspan.extent(1); j++) {
        for (std::size_t k=0; k!= md3Dspan.extent(2); k++) {
            std::print("{} ", md3Dspan[i, j, k]);
        }
      std::println("");
      }
   }

   return 0;
}
