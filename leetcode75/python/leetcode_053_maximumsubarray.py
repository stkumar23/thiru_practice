''' LeetCode - 53 - Maximum Subarray
    Given an array of integers nums, find the subarray with the largest sum,
    and return its sum.
    ex: nums = [-2,1,-3,4,-1,2,1,-5,4] => 6
    ex: nums = [5,4,-1,7,8] => 23

    Author: Thiru

    Time complexity: O(n)
    Space complexity: O(1) '''

''' Function to find the largest sum of subarray
    Get the sum of subarray from first element, by adding one element at a time
    Reset the current sum in case it is negative '''

from typing import List

def maxSubArray(nums: List[int]) -> int:
    maxSum = float('-inf')
    curSum = 0

    for n in nums:
        curSum += n
        maxSum = max(maxSum, curSum)

        if curSum < 0:
            curSum = 0
    return maxSum

# main
nums = [-2,1,-3,4,-1,2,1,-5,4]
#nums = [5,4,-1,7,8]

print("Maximum subarray sum: ", maxSubArray(nums))
