// LeetCode - 268 - Missing Number
// Given an array containing n distinct numbers in the range [0,n]
// return only the number in the range that is missing from the array
// Ex: nums = [3,0,1] => 2
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

class Leetcode268missingnumber {

  // Function to find the missing number from the given range 0 to n
  // Use XOR operator to find the missing number
  // XOR of any number with zero is the same number
  // XOR with 0 to n and then XOR with numbers from the given array
  // All the numbers will be duplicated except the missing number
  public int missingNumber(int[] v) {
    int res = v.length;

    for (int i=0; i<v.length; i++) {
      res ^= v[i] ^ i;
    }

    return res;
  }

  // main
  public static void main(String[] args)
  {
    int[] nums = {3,0,1};
    Leetcode268missingnumber obj = new Leetcode268missingnumber();
    System.out.println("The missing number is " + obj.missingNumber(nums));
  }
}
