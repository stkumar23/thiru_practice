// LeetCode - 53 - Maximum Subarray
// Given an array of integers nums, find the subarray with the largest sum,
// and return its sum.
// ex: nums = [-2,1,-3,4,-1,2,1,-5,4] => 6
// ex: nums = [5,4,-1,7,8] => 23
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <climits>

// Function to find the largest sum of subarray
// Get the sum of subarray from first element, by adding one element at a time
// Reset the current sum in case it is negative

int maxSubArray(const std::vector<int>& nums) {
  int maxSum = INT_MIN;
  int curSum = 0;

  for (int i=0; i<nums.size(); i++) {
    curSum += nums[i];
    maxSum = std::max(maxSum, curSum);

    if (curSum < 0)
      curSum = 0;
  }

  return maxSum;
}

// main
int main()
{
  std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  //std::vector<int> nums{5,4,-1,7,8};

  std::cout<<"Maximum subarray sum: " << maxSubArray(nums) << std::endl;

  return 0;
}
