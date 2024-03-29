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

import java.util.*;

public class Leetcode053maximumsubarray {

  // Function to find the largest sum of subarray
  // Get the sum of subarray from first element, by adding one element at a time
  // Reset the current sum in case it is negative

  int maxSubArray(int[] nums) {
    int maxSum = Integer.MIN_VALUE;
    int curSum = 0;

    for (int i=0; i<nums.length; i++) {
      curSum += nums[i];
      maxSum = Math.max(maxSum, curSum);

      if (curSum < 0)
        curSum = 0;
    }

    return maxSum;
  }

  // main
  public static void main(String[] args)
  {
    int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
    //int[] nums = {5,4,-1,7,8};

    Leetcode053maximumsubarray obj = new Leetcode053maximumsubarray();

    System.out.println("Maximum subarray sum: " + obj.maxSubArray(nums));
  }
}
