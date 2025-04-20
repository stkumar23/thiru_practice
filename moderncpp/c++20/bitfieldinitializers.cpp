// Modern C++ - C++20 - Default member initializer for Bit-fields
// From C++11 onwards, class data members can be initialized, but it was not
// enabled for bit-fields members. But, with C++20, this features is enabled,
// bit-field members can be initialized.
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>

// Sample structure definition using bit-fields
// This helps to save the size of the type.
// Now the Date type size is 8 bytes, instead of 12 bytes
struct Date {
    // Day is from 0 to 31, so 5 bits
    // Day is initialized with 1
    unsigned int Day : 5 = 1;
    // Month is from 0 to 12, so 4 bits
    // Month is initialized with 2
    unsigned int Month : 4 { 2 };
    unsigned int Year {2025};
};

int main()
{
  Date d;
  std::cout<<"Date is initialized as "
          <<d.Day<<"-"<<d.Month<<"-"<<d.Year<<std::endl;
  return 0;
}
