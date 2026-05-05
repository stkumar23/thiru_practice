// Modern C++ - C++23 - std::is_scoped_enum
// 
// std::is_scoped_enum checks whether T is a scoped enum or not
// Alias: std::is_scoped_enum_v 
//
// template< class T >
// constexpr bool is_scoped_enum_v = is_scoped_enum<T>::value;
//
// Scoped enum do not implicityly convert to integral types, 
// keep their enumerator names within their own scope.
//
// Use cases
// Can be used to restrict functions to only accept scoped enums
// which offer better type safety than unscoped enums.
//
// Defined in the header <type_traits>
//
// Compile with -std=c++23
// 
// Author: Thiru

#include <print> // for std::println
#include <type_traits>

enum class BodyType { Micro, Hatchback, Sedan, Suv, Truck, Van};
enum struct HybridType { Standard, Plugin};

int main() {

   std::println("{}", std::is_scoped_enum_v<int>);	// false
   std::println("{}", std::is_scoped_enum_v<double>);	// false
   std::println("{}", std::is_scoped_enum_v<BodyType>);	// true
   std::println("{}", std::is_scoped_enum_v<HybridType>);	// true

   return 0;
}
