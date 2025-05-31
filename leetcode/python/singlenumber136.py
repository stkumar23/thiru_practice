# LeetCode - 136 - Single Number
# Given a non-empty array of integers nums, every element appears twice
# except for one. Find that single one.
#
# ex: nums = [2,2,1] => 1
# ex: nums = [4,1,2,1,2] => 4
# ex: nums = [1] => 1
#
# Author: Thiru
#
# Time complexity: O(n)
# Space complexity: O(1)

from typing import List
import functools
import operator

class SingleNumber136:

    # Function to find single number
    # Using functools reduce to find the single number
    # operator.xor is passed to reduce function

    def singleNumber(self, nums: List[int]) -> int:
        return functools.reduce(operator.xor, nums, 0)

# main
obj = SingleNumber136()

#nums = [2,2,1]
nums = [4,1,2,1,2]
print("Single Number ", obj.singleNumber(nums))
