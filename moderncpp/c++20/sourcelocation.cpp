// Modern C++ - C++20 - Source Location
// The std::source_location class represents certain information about the
// source code such as file names, function names, line number, column number.
// Before C++20, predefined macros like __LINE__, __FILE__ are used.
//
// Defined in the header <source_location>
//
// Compile with -std=c++2a
//
// Author: Thiru

#include <iostream>
#include <source_location>
#include <string_view>

// sample log function
void logmsg(const std::string_view& msg,
            const std::source_location& loc = std::source_location::current()) {
  std::clog << "file: " << loc.file_name()
            << " " << loc.line() << ":" << loc.column()
            << " " << loc.function_name()
            << std::endl;
}

int main()
{
  logmsg ("Sample message");
  logmsg ("Modern C++");
  return 0;
}
