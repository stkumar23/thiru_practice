// LeetCode - 238 - Product of Array Except Self
// Given an array of integers nums, return an array res such that
// res[i] is equal to the product of all the elements of nums except nums[i]
// Do not use division operator
// ex: nums = [1,2,3,4] => [24,12,8,6]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>

// Function to return the product of array except self
// Use identify of multiplication 1, to multiply the array from left to right
// Use identify of multiplication 1, to multiply the array from right to left
// Multiply the results from both of these arrays

std::vector<int> prodcutOfArrayExceptSelf(const std::vector<int>& nums) {
  int size = nums.size();
  std::vector<int> res(size, 1);

  for (int i=1; i<size; i++) {
    res[i] = res[i-1] * nums[i-1];
  }

  int r = 1;
  for (int i=size-1; i>=0; i--) {
    res[i] = res[i] * r;
    r = r * nums[i];
  }

  return res;
}

// main
int main()
{
  std::vector<int> nums{1,2,3,4};
  std::vector<int> res = prodcutOfArrayExceptSelf(nums);

  for (const int& i: res) {
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
