''' LeetCode - 11 - Container With Most Water
    Given an array of integers height of length n. There are n vertical lines.
    Find two lines that together with the x-axis form a container, such that the
    container contains the most water.
    ex: height = [1,8,6,2,5,4,8,3,7] => 49

    Author: Thiru

    Time complexity: O(n)
    Space complexity: O(1) '''

from typing import List

''' Function to find the maximum area that the container can hold
    Find the minimum height from either side
    Find the distance between them and calculate the area it can hold
    Sliding window. Repeat and adjust left side and right side one by one
    to find the other max area if possible. '''

def maxArea(height: List[int]) -> int:
  left, right = 0, len(height) - 1
  maxContent = 0

  while left < right:
    if height[left] < height[right]:
      maxContent = max(maxContent, height[left] * (right - left))
      left += 1
    else:
      maxContent = max(maxContent, height[right] * (right - left))
      right -= 1

  return maxContent

# main
ht = [1,8,6,2,5,4,8,3,7]
print("The maximum area ", maxArea(ht))
