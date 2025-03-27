// simple program to understand line and branch coverage metrics using code
// coverage tool gcov and lcov.
//
// Compile the program with --coverage GCC flag. .gcno file will be created
// Run the program to generate .gcda file
//
// Generate code coverage report using below commands
// lcov --directory . --capture --output-file coverage.info
// genhtml --demangle-cpp -o coverage coverage.info

#include <iostream>

// Function checks whether the given number is a single digit or double.
// Function also checks invalid numbers
void checkdigits(const int& num) {
  if (num < 0 || num > 99) {
    std::cout<<"Invalid number"<<std::endl;
    return;
  }

  if (num >= 1 && num < 10) {
    std::cout<<"Single digit"<<std::endl;
  } else {
    std::cout<<"Double digit"<<std::endl;
  }
}

int main()
{
  int num = 5;
  checkdigits(num);

  num = 17;
  checkdigits(num);

  // Uncomment this line to see 100% line coverage
  // num = 101;
  // checkdigits(num);

  return 0;
}
