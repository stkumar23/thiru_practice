// Modern C++ - C++17 - std::from_chars
// std::from_chars - Efficiently converts the given string to integer format
// Defined in the header <charcov>
//
// Returns std::from_chars_result, which contains a ptr and ec (error code).
// ptr is a const char* and ec is of type std::errc
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <string_view>
#include <charconv>
#include <iomanip>

// Function to covert the given string into integer format using std::from_chars
// converstion returns the results on successful. Otherwise, returns
// appropriate error states, like, invalid argument (in case contains leading
// white spaces), out of range.
// The ptr will contain first non-matching character

void convertStrToInt(std::string_view str) {
  int result {};
  auto [ptr, ec] = std::from_chars(str.data(), str.data()+str.size(), result);

  if (ec == std::errc()) {
    std::cout<<"Result: " << result<<" ptr -> "<<std::quoted(ptr)<<std::endl;
  } else if (ec == std::errc::invalid_argument) {
    std::cout<<"This is not a number"<<std::endl;
  } else if (ec == std::errc::result_out_of_range) {
    std::cout<<"The number is larger than an int"<<std::endl;
  }
}

//main
int main()
{
  std::string_view str1{"43"};
  std::string_view str2{" 50"}; // leading whitespace
  std::string_view str3{"17 slices"}; // alphanumeric
  std::string_view str4{"12345678912"}; // large number. Can't hold in int

  convertStrToInt(str1);
  convertStrToInt(str2);
  convertStrToInt(str3);
  convertStrToInt(str4);

  return 0;
}
