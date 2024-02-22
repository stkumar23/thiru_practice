// Program to move all zero in the given array to the left side
// Move all the numbers to the right side in the same order
// Ex: [0,1,2,0,3,4,1,0,5] => [0,0,0,1,2,3,4,1,5]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

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
