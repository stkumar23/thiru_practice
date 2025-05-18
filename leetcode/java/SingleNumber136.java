// LeetCode - 136 - Single Number
// Given a non-empty array of integers nums, every element appears twice
// except for one. Find that single one.
//
// ex: nums = [2,2,1] => 1
// ex: nums = [4,1,2,1,2] => 4
// ex: nums = [1] => 1
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

class SingleNumber136 {

  // Function to find single number
  // Using XOR to find the single occurrence of the number
  // XOR of any number with 0 is that number
  // XOR of any number with itself is 0
  public int singleNumber(int[] nums) {
    int missingNumber = 0;

    for (int num : nums) {
        missingNumber ^= num;
    }

    return missingNumber;
  }

  public static void main(String[] args) {

    //int[] arr = {2,2,1};
    int[] arr = {4,1,2,1,2};

    SingleNumber136 obj = new SingleNumber136();
    System.out.println("Single Number " + obj.singleNumber(arr));
  }
}
