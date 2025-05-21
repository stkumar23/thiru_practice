# LeetCode - 26 - Remove Duplicates from Sorted Array
# Given an integer array nums sorted in non-decreasing order, remove 
# the duplicates in-place such that each unique element appears only once. 
# The relative order of the elements should be kept the same. Then return
# the number of unique elements in nums.
#
# ex: nums = [1,1,2] => 2
# ex: nums = [0,0,1,1,1,2,2,3,3,4] => 5
#
# Author: Thiru
#
# Time complexity: O(n)
# Space complexity: O(1)

from typing import List

class RemoveDupFromSortedArray26:
    # Function to remove the duplicates in the array - in-place
    # Start with the second index from left, compare elements at
    # current index and its previous index, place the value at
    # the unique index in case those are different.
    # Return the unique index

    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 0:
            return 0

        j = 1
        for i in range(1, len(nums)):
            if (nums[i] != nums[i-1]):
                nums[j] = nums[i]
                j += 1

        return j

# main

#nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

obj = RemoveDupFromSortedArray26()
ret = obj.removeDuplicates(nums)

print("The unique elements in the array " + str(ret));
for i in range(0, ret):
    print(nums[i], end = " ")
print()
