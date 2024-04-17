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

#include <iostream>
#include <vector>
#include <unordered_map>

// Function to find the duplicate numbers within the given k distance
// Use map to store the number and its array index. In case the number is
// already present in the map, compare the new and old indices range with k

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> umap;
  for(int i=0; i<nums.size(); i++) {
    if(umap.count(nums[i])) {
      if(i-umap[nums[i]] <= k) {
        return true;
      }
    }
    umap[nums[i]] = i;
  }
  return false;
}

// main
int main()
{
  std::vector<int> v = {1,2,3,1};
  int k = 3;

  std::cout<<"Container contains duplicate within the distance "<< k <<" is "
            <<std::boolalpha<<containsNearbyDuplicate(v, k)<<std::endl;
  return 0;
}
