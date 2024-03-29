// LeetCode - 152 - Maximum Product Subarray
// Given an array of integers nums, find a subarray that has the largest
// product
// ex: nums = [2,3,-2,4] => 6
// ex: nums = [-2,0,-1] => 0
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

public class Leetcode152maximumproductsubarray {

  // Function to find the maximum product subarray
  // Loop through the array from first index to last, find the max product
  // Loop through the array from last index to fist, find the max product
  // compare both product and find the max product

  int maxProduct(int[] nums)
  {
    int forPro = 1;
    int revPro = 1;

    int res = Integer.MIN_VALUE;
    int n = nums.length;

    for (int i=0; i<n; i++) {
      if (forPro == 0) forPro = 1;
      if (revPro == 0) revPro = 1;

      forPro *= nums[i];
      revPro *= nums[i];

      res = Math.max(res, Math.max(forPro, revPro));
    }

    return res;
  }

  // main
  public static void main(String[] args) {

    int[] nums = {2,3,-2,4};

    Leetcode152maximumproductsubarray obj = new Leetcode152maximumproductsubarray();
    System.out.println("Max Prouct " + obj.maxProduct(nums));

  }
}
