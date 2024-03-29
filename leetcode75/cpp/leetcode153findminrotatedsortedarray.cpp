// LeetCode - 153 - Find Minimim in Rotated Sorted Array
// Given an array of integers nums, sorted in ascending order is rotated
// between 1 and n times. Find minimum element of this array
// ex: nums = [4,5,6,7,0,1,2] => 0
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find the minimum in the rotated sorted array
// Use binary search, to find the mid element
// Check if mid element is lesser than previous element, return the mid element
// Check if right end of array is lesser than mid element, set left index
// Otherwise set right index

int findMin(const std::vector<int>& nums) {
  int size = nums.size();
  if (size == 0) {
    return -1;
  }

  if (size == 1) {
    return nums[0];
  }

  int left = 0;
  int right = size - 1;

  while (left < right) {
    int mid = left + (right - left)/2;
    if (mid > 0 && nums[mid] < nums[mid-1]) {
      return nums[mid];
    } else if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return nums[left];
}

// main
int main()
{
  std::vector<int> v = {4,5,6,7,0,1,2};
  std::cout << "Minimum element in the sorted array is " <<findMin(v)<< std::endl;

  return 0;
}
