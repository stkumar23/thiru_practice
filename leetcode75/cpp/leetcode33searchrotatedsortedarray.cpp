// LeetCode - 33 - Search in Rotated Sorted Array
// Given an array of integers nums, sorted in ascending order is rotated
// between 1 and n times. Find the index of target if it is array,
// otherwise return -1
// ex: nums = [4,5,6,7,0,1,2], target = 0 => index: 4
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find the given target in the rotated sorted array
// Use binary search, to find the mid element
// Check if mid element is target, if matches, return the mid index
// Otherwise search in the left side sorted array
// adjust the mid point based on the sorted group
// Or seach in the right side sorted array

int search(const std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left)/2;
    if (nums[mid] == target) {
      return mid;
    }

    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] <= target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return -1;
}

// main
int main()
{
  std::vector<int> v = {4,5,6,7,0,1,2};
  int target = 0;
  std::cout << "Index of an element in the rotated sorted array is "
            << search(v, target) << std::endl;

  return 0;
}
