// Modern C++ - C++11 - Scoped enums
// Prefer Scoped enums to unscoped enums
//
// Author: Thiru

// Underlying type for scoped enum is int by default.
// Unscoped enum have no default underlying type.
// Enumerators of scoped enums are converted to other types only with a cast

#include <iostream>

enum UnscopedColor {Blue, White, Green, Red};

enum class ScopedColor {SBlue, SWhite, SGreen, SRed};

int main()
{
  constexpr int pi = 3.14;

  // Use of unscoped enum
  // compared with double. compiles
  UnscopedColor usc = White;
  if (usc < pi) {
    std::cout<<"Unscoped color enum white is less than Pi value\n";
  }

  // Use of scoped enum. strong type
  ScopedColor sc = ScopedColor::SWhite; // can't use just SWhite
  // Below if condition will not compile
  // if (sc < pi) { // error! wont compile
  //   std::cout<<"Scoped color enum white is less than Pi value\n";
  // }

  // Compiles with type casting
  if (static_cast<double>(sc) < pi) {
    std::cout<<"Scoped color enum white is less than Pi value\n";
  }

  return 0;
}
