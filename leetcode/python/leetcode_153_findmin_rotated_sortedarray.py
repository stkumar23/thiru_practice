''' LeetCode - 153 - Find Minimim in Rotated Sorted Array
    Given an array of integers nums, sorted in ascending order is rotated
    between 1 and n times. Find minimum element of this array
    ex: nums = [4,5,6,7,0,1,2] => 0

    Author: Thiru

    Time complexity: O(logn)
    Space complexity: O(1) '''

''' Function to find the minimum in the rotated sorted array
    Use binary search, to find the mid element
    Check if mid element is lesser than previous element, return the mid element
    Check if right end of array is lesser than mid element, set left index
    Otherwise set right index '''

from typing import List

def findMin(nums: List[int]) -> int:
  size = len(nums)
  if size == 0:
    return -1

  if size == 1:
    return nums[0]

  left = 0
  right = size - 1

  while left < right:
    mid = left + (right - left)//2 # integer division

    if (mid > 0 and nums[mid] < nums[mid-1]):
      return nums[mid]
    elif (nums[mid] > nums[right]):
      left = mid + 1
    else:
      right = mid - 1

  return nums[left]

# main
nums = [4,5,6,7,0,1,2]
print("Minimum element in the sorted array is ", findMin(nums))
