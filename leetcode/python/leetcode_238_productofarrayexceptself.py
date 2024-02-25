''' LeetCode - 238 - Product of Array Except Self
    Given an array of integers nums, return an array res such that
    res[i] is equal to the product of all the elements of nums except nums[i]
    Do not use division operator
    ex: nums = [1,2,3,4] => [24,12,8,6]

    Author: Thiru

    Time complexity: O(n)
    Space complexity: O(n) '''

''' Function to return the product of array except self
    Use identify of multiplication 1, to multiply the array from left to right
    Use identify of multiplication 1, to multiply the array from right to left
    Multiply the results from both of these arrays '''

from typing import List

def prodcutOfArrayExceptSelf(nums: List[int]) -> List[int]:
    size = len(nums)
    res = [1] * size

    for i in range(1, size):
        res[i] = res[i-1] * nums[i-1]

    r = 1
    for i in range(size-1, -1, -1):
        res[i] *= r
        r *= nums[i]

    return res

# main
nums = [1,2,3,4]
res = prodcutOfArrayExceptSelf(nums)
print(res)
