// LeetCode - 219 - Contains Duplicate II
// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and
// abs(i-j) <= k
// ex: nums = [1,2,3,1], k = 3 => true
// ex: nums = [1,2,3,1,2,3], k = 2 => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

import java.util.Map;
import java.util.HashMap;

class ContainsDuplicate219 {

  // Function to find the duplicate numbers within the given k distance
  // Use map to store the number and its array index. In case the number is
  // already present in the map, compare the new and old indices range with k

  public boolean containsNearbyDuplicate(int[] nums, int k) {
    Map<Integer, Integer> umap = new HashMap<>();
    for(int i=0; i<nums.length; i++) {
      if(umap.containsKey(nums[i])) {
        if(i-umap.get(nums[i]) <= k) {
          return true;
        }
      }
      umap.put(nums[i], i);
    }
    return false;
  }

  // main
  public static void main(String[] args)
  {
    int[] arr = {1,2,3,1};
    int k = 3;

    ContainsDuplicate219 obj = new ContainsDuplicate219();
    System.out.println("Container contains duplicate within the distance " + k + " is "
              + obj.containsNearbyDuplicate(arr, k));
  }
}
