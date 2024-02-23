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

#include <iostream>
#include <vector>
#include <unordered_map>

// Function to find the target sum of given integers
// Use hashmap to check for difference value
// add index of last occurrence of a num

std::vector<int> twoSum(const std::vector<int>& n, const int& target)
{
  std::unordered_map<int, int> umap;
  std::vector<int> res;
  int size = n.size();

  for (int i=0; i<size; i++) {
    if (umap.find(target-n[i]) != umap.end()) {
      res.push_back(umap[target-n[i]]);
      res.push_back(i);
      return res;
    }
    umap[n[i]] = i;
  }
  return res;
}

// main
int main()
{
  std::vector<int> nums{2, 7, 11, 15};
  //std::vector<int> nums{3,2,4};
  int target = 9; //6;

  auto indices = twoSum(nums, target);
  std::cout<<"indices "<<indices[0]<<" "<<indices[1] << std::endl;

  return 0;
}
