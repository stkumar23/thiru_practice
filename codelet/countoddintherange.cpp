// Program to count all odd numbers in the given range, including starting and
// ending numbers.
// Ex: low = 1, high = 5. odd count = 3. [1,3,5]
// Ex: low = 1, high = 4. odd count = 2. [1,3]
//
// Author: Thiru

#include <iostream>
#include <vector>


// Function to move all zeros to the left side of the array
// Start from last index and swap elements if non-zero is found.

void moveZeroToLeft(std::vector<int>& v) {
  int right = v.size()-1;
  int left = right;

  while (left>=0) {
    if (v[left] != 0) {
      int t = v[left];
      v[left] = v[right];
      v[right] = t;
      right--;
    }
    left--;
  }
}


// main
int main()
{
  std::vector<int> nums = {0,1,2,0,3,4,1,0,5};

  moveZeroToLeft(nums);

  for (const auto& i: nums) {
    std::cout<<i<<" ";
  }
  return 0;
}
