# LeetCode - 217 - Contains Duplicate
# Given an integer array nums, return true if any value appears at least twice
# in the array, and return false if every element is distinct.
# ex: nums = [1,2,3,1] => true
# ex: nums = [1,2,3,4] => false
#
# Author: Thiru
#
# Time complexity: O(n)
# Space complexity: O(n)

from typing import List

class Leetcode217ContainsDuplicate:

  # Function to check whether the given container has any duplicate numbers
  # Use unorderd set to store all the elements and compare the size of set
  # with the given vector size. Set stores only unique numbers
  def containsDuplicate(self, nums: List[int]) -> bool:
    hs = set()
    for n in nums:
        if n in hs:
            return True
        hs.add(n)
    return False

# main
obj = Leetcode217ContainsDuplicate()
n = [1,2,3,1]

print("Container contains duplicate: ", obj.containsDuplicate(n))
