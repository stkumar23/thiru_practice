// Program to count all odd numbers in the given range,
// including starting and ending numbers.
// Ex: low = 1, high = 5. odd count = 3. [1,3,5]
// Ex: low = 1, high = 4. odd count = 2. [1,3]
//
// Author: Thiru
//
// Time complexity: O(1)
// Space complexity: O(1)

#include <iostream>

// Function to count odd numbers in the given range
// In case the starting and/or ending number is odd number,
// divide the range by 2 and plus 1.
// otherwise divide the range by 2 and return the count

int countOddInRange(const int& l, const int& h) {
  if (l%2 == 1 || h%2 == 1) {
    return ((h-l)/2)+1;
  } else {
    return (h-l)/2;
  }
}

// main
int main()
{
  int low = 1;
  int high = 4;

  std::cout<<"Odd count "<<countOddInRange(low, high)<<std::endl;

  return 0;
}
