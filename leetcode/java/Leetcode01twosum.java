// LeetCode - 01 - Two Sum
// Given an array of integers nums and an integer target, return
// indices of the two numbers such that they add up to target.
// ex: nums = [2,7,11,15], target = 9   => [0,1]
// ex: nums = [3,2,4], target = 6   => [1,2]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

import java.util.Map;
import java.util.HashMap;

class Leetcode01twosum {

  // Function to find the target sum of given integers
  // Use hashmap to check for difference value
  // add index of last occurrence of a num
  public int[] twoSum(int[] n, int target)
  {
    Map<Integer, Integer> umap = new HashMap<>();

    for (int i=0; i<n.length; i++) {
      int comp = target - n[i];
      if (umap.containsKey(comp)) {
        return new int[] {umap.get(comp), i};
      }
      umap.put(n[i], i);
    }
    return null;
  }

  // main
  public static void main(String[] arg)
  {
    int[] nums = {2, 7, 11, 15};
    int target = 9;

    Leetcode01twosum obj = new Leetcode01twosum();
    int[] res = obj.twoSum(nums, target);
    System.out.println("indices "+ res[0] + " " + res[1]);
  }
}
