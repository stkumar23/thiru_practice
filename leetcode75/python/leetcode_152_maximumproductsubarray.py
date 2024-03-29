''' LeetCode - 152 - Maximum Product Subarray
    Given an array of integers nums, find a subarray that has the largest
    product
    ex: nums = [2,3,-2,4] => 6
    ex: nums = [-2,0,-1] => 0

    Author: Thiru

    Time complexity: O(n)
    Space complexity: O(1) '''

''' Function to find the maximum product subarray
    Loop through the array from first index to last, find the max product
    Loop through the array from last index to fist, find the max product
    compare both product and find the max product '''

from typing import List

def maxProduct(nums: List[int]) -> int:
    forPro = 1
    revPro = 1

    res = float('-inf')
    n = len(nums)

    fIndex = 0
    rIndex = n -1

    while (fIndex < n and rIndex >= 0):
      if forPro == 0:
          forPro = 1
      if revPro == 0:
          revPro = 1

      forPro *= nums[fIndex]
      revPro *= nums[rIndex]

      fIndex += 1
      rIndex -= 1

      res = max(res, max(forPro, revPro))
    return res

# main
nums = [2,3,-2,4]
print("Max Prouct ", maxProduct(nums))
