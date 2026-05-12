// Modern C++ - C++23 - std::views::zip and std::views::zip_transform
// 
// std::views::zip is a range adaptor that combines multiple ranges into
// a single view of tuples. Each element in the resulting view is a 
// tuple-like object containing references to the corresponding elements
// from each input range
//
// The size of the resulting view is determined by the shortest input range.
//
// The view contains references to the original elements. If the underlying
// ranges are mutable, you can modify the original data through the zip view.
//
// std::views::zip_transform is a range adaptor that combines multiple ranges
// and applies a transformation function to their corresponding elements 
// simultaneously.
//
// Defined in the header <ranges>
//
// Compile with -std=c++23
// 
// Author: Thiru

#include <print>
#include <vector>
#include <string>
#include <ranges>

int main() {
   // currency conversion rates in INR
   std::vector<std::string> currency = {"USD", "CAD", "EUR"};
   std::vector<float> rates = {92.12, 68.18, 105.23};

   // zipping through two ranges together
   for (auto const& [cur, rate] : std::views::zip(currency, rates)) {
      std::println("{}: {} ", cur, rate);
   }

   // currency buy commission rate
   std::vector<float> commission = {3.15, 2.76, 4.31};

   std::println("Currency buying rate");
   auto buy_rate = std::views::zip_transform(std::minus<>{}, rates, commission);
   for (auto const& [cur, rate] : std::views::zip(currency, buy_rate)) {
      std::println("{}: {} ", cur, rate);
   }

   return 0;
}

