// LeetCode - 414 - Third Maximum Number
// Given an integer array nums, return the third distinct maximum number
// in the array. If the third maximum does not exist,
// return the maximum number.
//
// ex: nums = [3,2,1] => 1
// ex: nums = [1,2] => 2
// ex: nums = [2,2,3,1] => 1
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

class ThirdMaximumNumber414 {
    // Function to find third maximum number
    // Initialize three variables with long minimum
    // Compare the values and set first max, secondmax and thirdmax
    // In case the thirdmax is set to int minimum, return secondmax

    public int thirdMax(int[] nums) {
      long firstmax = Long.MIN_VALUE;
      long secondmax = Long.MIN_VALUE;
      long thirdmax = Long.MIN_VALUE;

      for (final int num: nums) {
          if (num > firstmax) {
              thirdmax = secondmax;
              secondmax = firstmax;
              firstmax = num;
          } else if ((num < firstmax) && (num > secondmax)) {
              thirdmax = secondmax;
              secondmax = num;
          } else if ((num < secondmax) && (num > thirdmax)) {
              thirdmax = num;
          }
      }

      return thirdmax == Long.MIN_VALUE ? (int) firstmax : (int) thirdmax;
    }

    public static void main(String[] args) {
      //int[] nums = {3,2,1};
      int[] nums = {2,2,3,1};
      //int[] nums = {1,2};

      ThirdMaximumNumber414 obj = new ThirdMaximumNumber414();
      System.out.println("Third Maximum Number " + obj.thirdMax(nums));
    }
}
