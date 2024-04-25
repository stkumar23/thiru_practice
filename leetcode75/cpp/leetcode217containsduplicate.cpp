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

#include <iostream>
#include <vector>
#include <unordered_set>

// Function to check whether the given container has any duplicate numbers
// Use unorderd set to store all the elements and compare the size of set
// with the given vector size. Set stores only unique numbers
bool containsDuplicate(std::vector<int>& nums) {
  std::unordered_set<int> s{};
  for(const auto& i: nums) {
    s.insert(i);
  }

  return s.size() != nums.size();
}

// main
int main()
{
  std::vector<int> n = {1,2,3,1};

  std::cout<<"Container contains duplicate: "
          <<std::boolalpha
          <<containsDuplicate(n)<<std::endl;

  return 0;
}
