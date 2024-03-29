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

import java.util.*;

public class Leetcode238productofarrayexceptself {

  // Function to return the product of array except self
  // Use identify of multiplication 1, to multiply the array from left to right
  // Use identify of multiplication 1, to multiply the array from right to left
  // Multiply the results from both of these arrays
  public int[] prodcutOfArrayExceptSelf(int[] nums) {
    int size = nums.length;
    int[] res = new int[size];

    res[0] = 1;
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
  public static void main(String[] args)
  {
    int[] nums = {1,2,3,4};

    Leetcode238productofarrayexceptself obj = new Leetcode238productofarrayexceptself();
    int[] res = obj.prodcutOfArrayExceptSelf(nums);

    for (int i: res) {
      System.out.print(i);
      System.out.print(" ");
    }
    System.out.println();
  }
}
