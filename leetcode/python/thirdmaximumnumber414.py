# LeetCode - 414 - Third Maximum Number
# Given an integer array nums, return the third distinct maximum number 
# in the array. If the third maximum does not exist, 
# return the maximum number.
#
# ex: nums = [3,2,1] => 1
# ex: nums = [1,2] => 2
# ex: nums = [2,2,3,1] => 1
#
# Author: Thiru
#
# Time complexity: O(n)
# Space complexity: O(1)

from typing import List
import math

class ThirdMaximumNumber414:
    # Function to find third maximum number
    # Initialize three variables with int minimum
    # Compare the values and set first max, secondmax and thirdmax
    # In case the thirdmax is set to int minimum, return secondmax

    def thirdMax(self, nums: List[int]) -> int:
        firstmax = -math.inf
        secondmax = -math.inf
        thirdmax = -math.inf

        for num in nums:
            if num > firstmax:
                thirdmax = secondmax
                secondmax = firstmax
                firstmax = num
            elif num < firstmax and num > secondmax:
                thirdmax = secondmax
                secondmax = num
            elif num < secondmax and num > thirdmax:
                thirdmax = num

        return firstmax if thirdmax == -math.inf else thirdmax

# main()
#nums = [3,2,1]
#nums = [2,2,3,1]
nums = [1,2]

obj = ThirdMaximumNumber414()
print("Third Maximum Number " + str(obj.thirdMax(nums)))
