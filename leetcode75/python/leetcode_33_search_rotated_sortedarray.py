''' LeetCode - 33 - Search in Rotated Sorted Array
    Given an array of integers nums, sorted in ascending order is rotated
    between 1 and n times. Find the index of target if it is array,
    otherwise return -1
    ex: nums = [4,5,6,7,0,1,2], target = 0 => index: 4

    Author: Thiru

    Time complexity: O(logn)
    Space complexity: O(1) '''

from typing import List

''' Function to find the given target in the rotated sorted array
    Use binary search, to find the mid element
    Check if mid element is target, if matches, return the mid index
    Otherwise search in the left side sorted array
    adjust the mid point based on the sorted group
    Or seach in the right side sorted array '''

def search(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1

    while left <= right:
      mid = left + (right - left)//2
      if nums[mid] == target:
        return mid

      if nums[left] <= nums[mid]:
        if nums[left] <= target and target <= nums[mid]:
          right = mid - 1
        else:
          left = mid + 1
      else:
        if nums[mid] <= target and target <= nums[right]:
          left = mid + 1
        else:
          right = mid - 1

    return -1

# main
nums = [4,5,6,7,0,1,2]
target = 0

print("Index of an element in the rotated sorted array is ",
    search(nums, target));
