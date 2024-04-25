// LeetCode - 217 - Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.
// ex: nums = [1,2,3,1] => true
// ex: nums = [1,2,3,4] => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

import java.util.*;

public class Leetcode217ContainsDuplicate {

  // Function to check whether the given container has any duplicate numbers
  // Use unorderd set to store all the elements and compare the size of set
  // with the given vector size. Set stores only unique numbers
  public boolean containsDuplicate(int[] nums) {
    HashSet<Integer> hs = new HashSet<>();
    for(int i: nums) {
      if(!hs.add(i))
        return true;
    }

    return false;
  }

  // main
  public static void main(String[] args)
  {
    int[] n = {1,2,3,1};

    Leetcode217ContainsDuplicate obj = new Leetcode217ContainsDuplicate();
    System.out.println("Container contains duplicate: " + obj.containsDuplicate(n));
  }
}
