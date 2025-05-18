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

class SingleNumber136:

    # Function to find single number
    # Using XOR to find the single occurrence of the number
    # XOR of any number with 0 is that number
    # XOR of any number with itself is 0
    def singleNumber(self, nums: List[int]) -> int:
        missingNumber = 0

        for num in nums:
            missingNumber ^= num

        return missingNumber

# main
obj = SingleNumber136()

nums = [2,2,1]
#nums = [4,1,2,1,2]
print("Single Number ", obj.singleNumber(nums))
